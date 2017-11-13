/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

#include "Ai.h"
#include <cstdlib>
#include <engine/MoveChar.h>
#include <engine/Attack.h>


ai::Ai::Ai(){
    
    
}

ai::Ai::Ai(int team){
    Team=team;
    
}

ai::Ai::~Ai(){
    
}

void ai::Ai::play(engine::Engine& engine,int character,state::State& state){
    if (Id==1){
        
        
        
        if(state.list_element[character].Team==Team){
            
                if(engine.mov_left!=0){
                     int random=std::rand();
        engine::MoveChar command(character,(random%4+1)*2);
        engine.addCommand(command);}
                }
        }
       
    
}

