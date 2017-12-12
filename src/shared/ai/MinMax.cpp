#include "state/State.h"
#include "MinMax.h"
#include <iostream>

ai::MinMax::MinMax() {


}

ai::MinMax::~MinMax() {

}

ai::MinMax::MinMax(int team) {
Team=team;

}


engine::Command ai::MinMax::play(engine::Engine& engine,int character,state::State& state){
    if(state.list_element[character].getTeam()==Team){
    	create_tree(state,engine,2);
	engine::Command command=list_mov[solve(state, Team,tree)];
    	if(engine.att_left==0)
        if(engine.mov_left!=0)
    		command=list_mov[solve(state, Team,tree)];
	if(engine.mov_left==0)
	if(engine.att_left!=0)
    		command=list_att[solve(state, Team,tree)];


   	 command.setCharacter(engine.char_sel);
   	 engine.addCommand(command);
   	 std::vector<ai::Node> clear;
   	 tree = clear;}
     else{
	if(Team==0)
	std::cout<<"C'est au tour des bleus"<<std::endl;
	if(Team==1)
	std::cout<<"C'est au tour des rouges"<<std::endl;

	}
	engine::Command com;
return com;
	}
void ai::MinMax::create_tree(state::State& state,engine::Engine& engine, int depth) {
    state_tempo = state.clone();
    std::vector<engine::Command> record;

    ai::Node origine(0, 0, Team,-1,tree.size());
    tree.push_back(origine);

    this->recursive(1, state_tempo, engine.mov_left + engine.att_left, record, depth,0,engine);

    std::cout << "le nombre de noeud :" << tree.size() << std::endl;
}







void ai::MinMax::recursive(int depth, state::State& state, int depart, std::vector<engine::Command> record, int ordre,int id_parent,engine::Engine& engine) {

if(depth <ordre +1 ){
	std::vector<engine::Command> list_command;
        for(unsigned i = 0 ; i<list_att.size(); i ++)
		list_command.push_back(list_att[i]);
	for(unsigned i = 0 ; i<list_mov.size(); i ++)
		list_command.push_back(list_mov[i]);



       if(engine.att_left==0)
	if(engine.mov_left!=0)
	for(unsigned i = 0 ; i<list_mov.size(); i ++){
		if ( list_command[i].execute(state) == 0){


			ai::Node node2(depth,i, static_cast<int>((depart-depth)/4)%2+Team,id_parent,tree.size());

			score(node2,state,node2.team);
			//std::cout<<node2.get_score()<<std::endl;
			tree.push_back(node2);
			this->recursive(depth + 1 , state, depart - 1, record, ordre ,i,engine);
			list_command[i].undo(state);



		}


		}
	if(engine.mov_left==0)
	if(engine.att_left!=0)
	for(unsigned i = list_mov.size() ; i<list_command.size(); i ++){
		if ( list_command[i].execute(state) == 0){


			ai::Node node2(depth,i, static_cast<int>((depart-depth)/4)%2+Team,id_parent,tree.size());

			score(node2,state,node2.team);
			//std::cout<<node2.get_score()<<std::endl;
			tree.push_back(node2);
			this->recursive(depth + 1 , state, depart - 1, record, ordre ,i,engine);
			list_command[i].undo(state);



		}


		}
	if(engine.mov_left!=0)
	if(engine.att_left!=0)
	for(unsigned i = 0 ; i<list_command.size(); i ++){
		if ( list_command[i].execute(state) == 0){


			ai::Node node2(depth,i, static_cast<int>((100000+depart-depth)/4)%2+Team,id_parent,tree.size());

			score(node2,state,node2.team);
			//std::cout<<node2.get_score()<<std::endl;
			tree.push_back(node2);
			this->recursive(depth + 1 , state, depart - 1, record, ordre ,i,engine);
			list_command[i].undo(state);



		}


		}






	}

}



void ai::MinMax::score(ai::Node& node, const state::State& state, int team) {
    int pdv_0 = 0;
    int pdv_1 = 0;
    for(int i = 0;i<state.nb_hero;i++){
        if(state.list_element[i].getTeam()==0)
            pdv_0=pdv_0+state.list_element[i].getLife();
        if(state.list_element[i].getTeam()==1)
            pdv_1=pdv_1+state.list_element[i].getLife();}


    if(team==1)
    node.set_score(pdv_1-pdv_0);
    if(team==0)
    node.set_score(pdv_0-pdv_1);

}

int ai::MinMax::solve(const state::State& state, int team, std::vector<ai::Node> tree) {
 int depth = 2;
 int ind=0;
 int max=-100;
 int min=100;



while (depth > 0) {
std::cout << depth << std::endl;
for(unsigned int i=0;i<tree.size();i++){
	if(tree[i].depth == depth){
		if(tree[i].team == Team){
			//std::cout<<"le max est : "<<tree[i].get_score()<<std::endl;
			if(tree[i].get_score()>max){
                    max = tree[i].get_score();
                    ind = tree[i].id;
            }
        }
    }
    else {
        if(tree[i].get_score()<min){
            min = tree[i].get_score();
            ind = tree[i].id;
        }
    }
}


depth--;
}




/*int depth = 3;
    int ind=0;
    int max=0;
    int min=100;



    while (depth > 0) {

        std::cout << depth << std::endl;
        for(int i=0;i<tree.size();i++){

            if(tree[i].depth==depth-1){
                if(tree[i].team==1){
                max=0;
                ind=0;
                for(int j=i;j<tree.size();j++){
                    if(tree[j].depth==depth){
                        ind++;
                    if(ind<tree[i].nb_child)
                        if(tree[j].get_score()>max){
                            max=tree[j].get_score();
                            tree[i].set_score(max);
                            tree[i].set_ind_sol(tree[j].width);
                            //std::cout<<"la solution est "<<tree[j].get_ind_sol()<<" pour "<<tree[i].get_ind_sol()<<std::endl;
                        }

                    }
                }
                }
                if(tree[i].team==2){
                min=100;
                ind=0;
                for(int j=i;j<tree.size();j++){
                    if(tree[j].depth==depth){
                        ind++;
                    if(ind<tree[i].nb_child)
                        if(tree[j].get_score()<min){
                            min=tree[j].get_score();
                            tree[i].set_score(min);
                            tree[i].set_ind_sol(tree[j].width);
                            //std::cout<<"la solution est "<<tree[j].get_ind_sol()<<" pour "<<tree[i].get_ind_sol()<<std::endl;
                        }

                    }
                }
                }



            }


        }



        depth--;
    }
    std::cout<<"la solution est "<<tree[0].get_score()<<std::endl;
    return tree[0].get_ind_sol();*/
    return ind;
}
