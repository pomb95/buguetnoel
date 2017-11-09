/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

#include "Engine.h"
#include "Command.h"
#include "MoveChar.h"
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
    std::cout << "IL reste  : " << commands.size() <<"commandes"<< std::endl;    
    if(!commands.empty()){
        commands[0].execute(state_game);  
        commands.erase(commands.begin()); 
    }
    state_game.enable_render=1;
}


void engine::Engine::testInit(){
    engine::MoveChar command1(1,2);
    this->addCommand(command1);
    this->addCommand(command1);
    command1.setDirection(6);
    this->addCommand(command1);
    this->addCommand(command1);
    command1.setDirection(8);
    this->addCommand(command1);
    this->addCommand(command1);
    this->addCommand(command1);
    this->addCommand(command1);
    this->addCommand(command1);
    this->addCommand(command1);
    this->addCommand(command1);//test collision haut avec Eni
    this->addCommand(command1);
    this->addCommand(command1);
    this->addCommand(command1);
    this->addCommand(command1);
    engine::MoveChar command3(3,6); //test collision droite avec enu
    this->addCommand(command3);
    this->addCommand(command3);
    this->addCommand(command3);
    this->addCommand(command3);
//test pour attack
engine::Attack command2(1,2,10); // L'éni attaque le sram

this-> addCommand(command2);

std::cout<< "commande ajouté attaque" <<std::endl;

    
}
