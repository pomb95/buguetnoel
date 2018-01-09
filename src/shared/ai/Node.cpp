#include "Node.h"

ai::Node::Node (){
    score=0;
    ind_sol=-1;
}
ai::Node::~Node (){
   
}
ai::Node::Node (int depth,int id,int team,int id_parent,int site){
    this->depth=depth;
    this->id=id;
    this->id_parent=id_parent;
    this->team=team;
   this->site=site;
    score=0;
    ind_sol=-1;
    nb_child=0;
}


int ai::Node::get_ind_sol(){
    return ind_sol;
}

int ai::Node::get_score(){
    return score;
}
void ai::Node::set_ind_sol(int ind_sol){
    this->ind_sol=ind_sol;
}

void ai::Node::set_score(int score){
    this->score=score;
}
