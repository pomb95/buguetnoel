/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

#include <iostream>
#include "CommandCenter.h"

namespace state {
    CommandCenter::CommandCenter() : Building() {
        Name = "Command Center";
        Life = 500;
        std::cout << Name << " created" << std::endl;
    }
    CommandCenter::~CommandCenter() {}
    
    void CommandCenter::getDamage (int damage){
        Life -= damage;
        std::cout << "Un " << Name << " reçoit des dégâts !" << std::endl;
    }
    
    bool CommandCenter::isAlive (){
        return Life > 0 ;
    }
}