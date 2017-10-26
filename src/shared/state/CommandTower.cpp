/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

#include <iostream>
#include "CommandTower.h"

namespace state {
    CommandTower::CommandTower(int team) : Building(team) {
        Name = "Command Tower";
        typeId = COMMANDTOWER;
        std::cout << Name << " created" << std::endl;
    }
    CommandTower::~CommandTower() {}
    
    void CommandTower::getStatus (){
        std::cout << " " << std::endl;
        std::cout << "Name : " << Name << std::endl;
        std::cout << "TypeId : " << typeId << std::endl;
        std::cout << "ATK : " << ATK << std::endl;
        std::cout << "Team : " << Team << std::endl;
        std::cout << " " << std::endl;
    }
}
