#include "MoveChar.h"
#include <iostream>
#include "Command.h"
#include <state/MobileElement.h>

engine::MoveChar::MoveChar(int c, int d) {
    Id=1;
    character=c;
    direction=d;
}

engine::MoveChar::~MoveChar(){
    
}

void engine::MoveChar::setCharacter(int c){
    this->character = c;
}

void engine::MoveChar::setDirection(int d){
    this->direction = d;
}

void engine::MoveChar::setMoveChar(int c, int d){
    this->character = c;
    this->direction = d;
}