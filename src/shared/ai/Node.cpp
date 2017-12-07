#include "Node.h"

ai::Node::Node (){
    score=0;
    ind_sol=-1;
}
ai::Node::~Node (){
   
}
ai::Node::Node (int depth){
    this->depth=depth;
}
ai::Node::Node (int depth,int width,int team){
    this->depth=depth;
    this->width=width;
    this->team=team;
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