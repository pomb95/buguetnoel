/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

#include "Engine.h"
#include "Command.h"
#include "MoveChar.h"
#include "CheckAround.h"
#include "Attack.h"
#include <iostream>
#include <vector>


engine::Engine::Engine() {
    /*engine::MoveChar command(0,0);
    this->addCommand(command);*/
    char_sel=0;
    mov_left=3;
    att_left=1;
}

engine::Engine::~Engine() {}

void engine::Engine::addCommand(Command cmd){
    commands.push_back(cmd);
    
}



void engine::Engine::Update(state::State& state_game) {
   // std::cout << "Il reste  : " << commands.size() <<" commandes "<< std::endl;    
    state_game.list_element[char_sel].selected=1;
    if(!commands.empty()){
        commands[0].execute(state_game);  
        if(commands[0].getId()==1)
            mov_left=mov_left-1;
        
        commands.erase(commands.begin()); 
    }
    state_game.enable_state=1;
    
    
        if(mov_left==0)
        {
        state_game.list_element[char_sel].selected=0;
        char_sel=(char_sel+1)%6;
        mov_left=state_game.list_element[char_sel].Movement;
        state_game.list_element[char_sel].selected=1;
        
        }
    //std::cout<<state_game.list_element[char_sel].getName()<<std::endl;
//std::cout << "Engine :::On a notifié à l'état que une commande a été executé "<< std::endl; 
}


void engine::Engine::testInit(){
   


    
}
