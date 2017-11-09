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
}

engine::Engine::~Engine() {}

void engine::Engine::addCommand(Command cmd){
    commands.push_back(cmd);
    
}



void engine::Engine::Update(state::State& state_game) {
    std::cout << "Il reste  : " << commands.size() <<" commandes "<< std::endl;    
    if(!commands.empty()){
        commands[0].execute(state_game);  
        commands.erase(commands.begin()); 
    }
    state_game.enable_render=1;
}


void engine::Engine::testInit(){
    engine::CheckAround check(1);
    engine::MoveChar command1(1,2);
    this->addCommand(command1);
    this->addCommand(command1);
    this->addCommand(check);
    command1.setDirection(4);
    this->addCommand(command1);
    this->addCommand(command1);
    command1.setDirection(2);
    this->addCommand(command1);
    this->addCommand(command1);
    this->addCommand(command1);
    this->addCommand(check);
    this->addCommand(command1);
    this->addCommand(command1);
    this->addCommand(command1);
    this->addCommand(command1);
    this->addCommand(command1);
    this->addCommand(command1);
    this->addCommand(check);
    this->addCommand(command1);
    this->addCommand(command1);
    command1.setMoveChar(3,6);//test collision droite avec enu
    this->addCommand(command1);
    this->addCommand(command1);
    this->addCommand(command1);
    this->addCommand(command1);
//test pour attack
engine::Attack command2(1,2,10); // L'éni attaque le sram

this-> addCommand(command2);

std::cout<< "commande ajouté attaque" <<std::endl;

    
}
