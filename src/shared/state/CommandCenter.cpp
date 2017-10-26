/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

#include <iostream>
#include "CommandCenter.h"

namespace state {
    CommandCenter::CommandCenter(int team) : Building(team) {
        Name = "Command Center";
        typeId = COMMANDCENTER;
        Life = 500;
        ATK = 15;
        std::cout << Name << " created " << std::endl;
    }
    CommandCenter::~CommandCenter() {}
    
    void CommandCenter::getDamage (int damage){
        Life -= damage;
        std::cout << "Un " << Name << " reçoit des dégâts !" << std::endl;
        if (!isAlive()) std::cout << "Un " << Name << " a été détruit :(" << std::endl;
    }
    
    bool CommandCenter::isAlive(){
        return Life > 0 ;
    }
    
    void CommandCenter::getStatus(){
        std::cout << " " << std::endl;
        std::cout << "Name : " << Name << std::endl;
        std::cout << "TypeId : " << typeId << std::endl;
        std::cout << "Team : " << Team << std::endl;
        std::cout << "Life : " << Life << std::endl;
        std::cout << "ATK : " << ATK << std::endl;
        std::cout << "Etat : " << isAlive() << std::endl;
        std::cout << " " << std::endl;
    }
    
}