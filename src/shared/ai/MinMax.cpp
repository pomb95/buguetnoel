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


void ai::MinMax::play(engine::Engine& engine,int character,state::State& state){
    create_tree(state,engine,2);
    
    engine::Command command=list_mov[solve(state, state.list_element[character].getTeam(),tree)];
    command.setCharacter(engine.char_sel);
    engine.addCommand(command);
    
}
void ai::MinMax::create_tree(state::State& state,const engine::Engine& engine, int depth) {
    state_tempo = state.clone();
    std::vector<engine::Command> record;
    


    ai::Node origine(0, 0, Team);
    tree.push_back(origine);

    this->recursive(depth, state_tempo, engine.mov_left + engine.att_left, record, 1);



    std::cout << "le nombre de noeud :" << tree.size() << std::endl;
}

void ai::MinMax::recursive(int depth, state::State& state, int depart, std::vector<engine::Command> record, int ordre) {









/*
    if (ordre > 0) {

        std::vector<engine::Move_unit> list_action;
        ia::Attack attack;
        attack.init(state,(depart / 3) % 2 + 1);
        //std::cout<<"le gang est "<<(depart / 3) % 2 + 1<<std::endl;

        ia::Defence defence;
        defence.init(state, (depart / 3) % 2 + 1);
        for (int k = 0; k < defence.list_defence.size(); k++)
            list_action.push_back(defence.list_defence[k]);
        for (int k = 0; k < attack.list_attack.size(); k++){
            list_action.push_back(attack.list_attack[k]);
            //std::cout<<"On attaque "<<attack.list_attack[k].id_terr_to<<" avec "<<attack.list_attack[k].id_terr_from<<std::endl;
        }


        //std::cout<<attack.list_attack.size()<<std::endl;
        
        tree[tree.size() - 1].nb_child = list_action.size();

        for (int ki = 0; ki < list_action.size(); ki++) {


            list_action[ki].make(state);

            ia::Node node2(depth, ki, (depart / 3) % 2 +1);

            if (ordre == 1)
                this->score(node2, state_tmp, 1);
            //std::cout<<node2.get_score()<<"    "<<ordre<<" "<<node2.depth<<std::endl;
            tree.push_back(node2);
            this->recursive(depth + 1, state, depart + 1, record, ordre - 1);


            list_action[ki].demake(state);
        }


    }*/
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
    return 1;
}
