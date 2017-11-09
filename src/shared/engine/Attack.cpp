#include "Attack.h"
#include <iostream>
#include "Command.h"
#include <state/MobileElement.h>

engine::Attack::Attack(int c, int d,int damage) {
    Id=2;
    attaquant= c;
    victime = d;
    degat = damage;
}

engine::Attack::~Attack(){
    
}

void engine::Attack::setAttaquant(int c){
    this->attaquant = c;
}

void engine::Attack::setVictime(int d){
    this->victime = d;
}



void engine::Attack::setAttack(int c, int d){
    this->attaquant = c;
    this->victime = d;
}
