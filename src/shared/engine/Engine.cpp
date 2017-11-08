/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

#include "Engine.h"
#include "Command.h"
#include "MoveChar.h"
#include <iostream>


engine::Engine::Engine() {
    engine::MoveChar command1(1,2);
    this->addCommand(command1);


}

engine::Engine::~Engine() {}

void engine::Engine::addCommand(Command cmd){
    commands.push_back(cmd);
}

void engine::Engine::Update(state::State& state_game) {
    
    commands[0].execute(state_game);
    state_game.enable_render=1;
    
}