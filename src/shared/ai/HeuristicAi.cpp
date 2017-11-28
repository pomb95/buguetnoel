/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

#include <iostream>
#include <vector>
#include "HeuristicAi.h"
#include "Ai.h"
#include <cstdlib>
#include <iostream>
#include <math.h>
#include "engine.h"
#include "ai.h"
#include <engine/MoveChar.h>
#include <engine/Attack.h>
#include <engine/CheckAround.h>
#include <sys/time.h>

float distance(int x1, int y1, int x2, int y2);

ai::HeuristicAi::HeuristicAi() {
    Id=2;
}
ai::HeuristicAi::~HeuristicAi() {}
ai::HeuristicAi::HeuristicAi(int team) {
    Id=2;
    Team=team;
}




void ai::HeuristicAi::play(engine::Engine& engine,int character,state::State& state){
   
int id_max_mov = 0;
int id_max_att = 0;
int value = 0;
//engine::CheckAround command0(character);
//engine.addCommand(command0);
if(state.list_element[character].getTeam()==Team){

    if(engine.mov_left!=0){
       
        clearListInt(score_mov);
        scor_mov(state,character);
        
        for (unsigned i=0; i<score_mov.size(); i++)
            if (score_mov[i] > value) {
                value = score_mov[i];

                }


        for (unsigned i=0; i<list_mov.size(); i++)
            if (score_mov[i] == value) {
                id_max_mov = i;
                break;
                }
        engine::Command command=list_mov[id_max_mov];
        command.setCharacter(character);
        engine.addCommand(command);

    }
    else {
        if(engine.att_left!=0){
            for (unsigned i=0; i<score_att.size(); i++)
                if (score_att[i] > value) {
                    value = score_att[i];

                    }

            for (unsigned i=0; i<list_att.size(); i++)
            if (score_att[i] == value) {
                id_max_att = i;
                break;
                }
            engine::Command command=list_att[id_max_att];
            command.setAttaquant(character);
            engine.addCommand(command);
                }
        }
    }



}

float distance(int x1, int y1, int x2, int y2){
    int case_x=abs(x1-x2)/28;
    int case_y=abs(y1-y2)/28;
    return case_x+case_y;
}

void ai::HeuristicAi::scor_mov(state::State& state, int character){
    int posX = static_cast<int>(state.list_element[character].getPosX());
    int posY = static_cast<int>(state.list_element[character].getPosY());
    int range = state.list_element[character].getRange();
    
    for(int i=0;i<state.nb_hero;i++)
        if(state.list_element[character].getTeam()!=state.list_element[i].getTeam())
            std::cout<<"Le joueur est a "<<distance(posX,posY,static_cast<int>(state.list_element[i].getPosX()),static_cast<int>(state.list_element[i].getPosY()))<<" du "<<state.list_element[i].getName()<<" adverse"<<std::endl;
        
               
    
    
    
}