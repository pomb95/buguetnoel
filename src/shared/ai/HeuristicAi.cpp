/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

#include <iostream>
#include "HeuristicAi.h"
#include "Ai.h"
#include <cstdlib>
#include <iostream>
#include <engine/MoveChar.h>
#include <engine/Attack.h>
#include <engine/CheckAround.h>
#include <sys/time.h>

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
engine::CheckAround command0(character);
engine.addCommand(command0);
if(state.list_element[character].getTeam()==Team){

    if(engine.mov_left!=0){
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
