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

