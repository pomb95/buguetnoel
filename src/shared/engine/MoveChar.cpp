#include "MoveChar.h"
#include <iostream>
#include "Command.h"

engine::MoveChar::MoveChar(int c, int d) {
    Id=1;
    character=c;
    direction=d;
}

engine::MoveChar::~MoveChar(){
    
}

void engine::MoveChar::setMoveChar(int c, int d){
    this->character = c;
    this->direction = d;
}

void engine::MoveChar::serialize(Json::Value& out){
	out["command"]=getId();	
	out["character"]=getCharacter();	
	out["direction"]=getDirection();
	

}
