/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

#include "ai.h"
#include <cstdlib>
#include <iostream>
#include <engine.h>
#include <engine/MoveChar.h>
#include <engine/Attack.h>

#include <sys/time.h>


ai::Ai::Ai() {}


ai::Ai::~Ai() {}


void ai::Ai::init(){
    //implémentation des commandes de déplacement
    engine::MoveChar command1(0,2);
    engine::MoveChar command2(0,4);
    engine::MoveChar command3(0,6);
    engine::MoveChar command4(0,8);
    //poids initial des commandes
    list_mov.push_back(command1);
    score_mov.push_back(0);
    list_mov.push_back(command2);
    score_mov.push_back(0);
    list_mov.push_back(command3);
    score_mov.push_back(0);
    list_mov.push_back(command4);
    score_mov.push_back(0);

    //idem pour attaquer
    engine::Attack command5(0,0);
    engine::Attack command6(0,1);
    engine::Attack command7(0,2);
    engine::Attack command8(0,3);
    engine::Attack command9(0,4);
    engine::Attack command10(0,5);
    list_att.push_back(command5);
    score_att.push_back(0);
    list_att.push_back(command6);
    score_att.push_back(0);
    list_att.push_back(command7);
    score_att.push_back(0);
    list_att.push_back(command8);
    score_att.push_back(0);
    list_att.push_back(command9);
    score_att.push_back(0);
    list_att.push_back(command10);
    score_att.push_back(0);
}

void ai::Ai::clearListInt(std::vector<int> score){
    for (unsigned int i = 0; i < score.size(); i++){
        score[i] = 0;
    }
}
