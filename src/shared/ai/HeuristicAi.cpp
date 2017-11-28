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

std::vector<int> distance(int x1, int y1, int x2, int y2);

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
       
        
        scor_mov(state,character);
        for(int i=0;i<score_mov.size();i++)
            std::cout<<score_mov[i]<<std::endl;
        
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
        for(int i=0;i<score_mov.size();i++)
            score_mov[i]=0;

    }
    else {
        if(engine.att_left!=0){
            
            scor_att(state,character);
            for(int i=0;i<score_att.size();i++)
            std::cout<<score_att[i]<<std::endl;
            for (unsigned i=0; i<score_att.size(); i++)
                if (score_att[i] > value) {
                    value = score_att[i];
                    }

            for (unsigned i=0; i<list_att.size(); i++)
            if (score_att[i] == value) {
                id_max_att = i;
                break;
                }
            std::cout<<value<<std::endl;
            engine::Command command=list_att[id_max_att];
            command.setAttaquant(character);
            engine.addCommand(command);
            for(int i=0;i<score_att.size();i++)
                score_att[i]=0;
                }
        }
    }



}

std::vector<int> distance(int x1, int y1, int x2, int y2){
    int case_x=(x1-x2)/28;
    int case_y=(y1-y2)/28;
    std::vector<int> output;
    output.push_back(abs(case_x)+abs(case_y));
    output.push_back(case_x);
    output.push_back(case_y);
    return output;
}

void ai::HeuristicAi::scor_mov(state::State& state, int character){
    int target = -1;
    int posX = static_cast<int>(state.list_element[character].getPosX());
    int posY = static_cast<int>(state.list_element[character].getPosY());
    int range = state.list_element[character].getRange();
    int min = 10000;
    // on cherche le hero vivant le plus proche
    for(int i=0;i<state.nb_hero;i++)
        if(state.list_element[i].getAlive()==1)
        if(state.list_element[character].getTeam()!=state.list_element[i].getTeam()){
            std::cout<<"Le joueur est a "<<distance(posX,posY,static_cast<int>(state.list_element[i].getPosX()),static_cast<int>(state.list_element[i].getPosY()))[0]<<" du "<<state.list_element[i].getName()<<" adverse"<<std::endl;
           
            if(distance(posX,posY,static_cast<int>(state.list_element[i].getPosX()),static_cast<int>(state.list_element[i].getPosY()))[0]<min){
                min=distance(posX,posY,static_cast<int>(state.list_element[i].getPosX()),static_cast<int>(state.list_element[i].getPosY()))[0];
                target=i;        
            }
        }
    std::cout<<"La cible est"<<state.list_element[target].getName()<<std::endl;
    //on se deplace vers le hero cible
    if (distance(posX,posY,static_cast<int>(state.list_element[target].getPosX()),static_cast<int>(state.list_element[target].getPosY()))[1]< 0)
    {
        score_mov[2]++;
    }
    if (distance(posX,posY,static_cast<int>(state.list_element[target].getPosX()),static_cast<int>(state.list_element[target].getPosY()))[1]> 0)
    {
        score_mov[1]++;}
    
    if (distance(posX,posY,static_cast<int>(state.list_element[target].getPosX()),static_cast<int>(state.list_element[target].getPosY()))[2]< 0)
    {
        score_mov[0]++;
    }
    if (distance(posX,posY,static_cast<int>(state.list_element[target].getPosX()),static_cast<int>(state.list_element[target].getPosY()))[2]> 0)
    {
        score_mov[3]++;
    }
    
           
    
}

void ai::HeuristicAi::scor_att(state::State& state, int character){
    int target = -1;
    int posX = static_cast<int>(state.list_element[character].getPosX());
    int posY = static_cast<int>(state.list_element[character].getPosY());
    int range = state.list_element[character].getRange();
    int min = 10000;
    // on cherche le hero vivant le plus proche
    for(int i=0;i<state.nb_hero;i++)
        if(state.list_element[i].getAlive()==1)
        if(state.list_element[character].getTeam()!=state.list_element[i].getTeam()){
            std::cout<<"Le joueur est a "<<distance(posX,posY,static_cast<int>(state.list_element[i].getPosX()),static_cast<int>(state.list_element[i].getPosY()))[0]<<" du "<<state.list_element[i].getName()<<" adverse"<<std::endl;
           
            if(distance(posX,posY,static_cast<int>(state.list_element[i].getPosX()),static_cast<int>(state.list_element[i].getPosY()))[0]<min){
                min=distance(posX,posY,static_cast<int>(state.list_element[i].getPosX()),static_cast<int>(state.list_element[i].getPosY()))[0];
                target=i;        
            }
        }
    std::cout<<"La cible est "<<state.list_element[target].getName()<<std::endl;
    
    this->score_att[target]++;
    
}