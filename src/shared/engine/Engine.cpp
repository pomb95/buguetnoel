/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

#include "Engine.h"
#include "Command.h"
#include "MoveChar.h"


engine::Engine::Engine() {}

engine::Engine::~Engine() {}

void engine::Engine::addCommand(Command* cmd){
    commands.push_back(cmd);
}

void engine::Engine::Update() {
    for (Command& command: commands){
        command -> Command::execute(&currentState);
    }
}