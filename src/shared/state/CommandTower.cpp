/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

#include <iostream>
#include "CommandTower.h"

namespace state {

    CommandTower::CommandTower() : Building() {
        Name = "Command Tower";
        typeId = COMMANDTOWER;
      //  std::cout << Name << " created" << std::endl;
    }
    CommandTower::~CommandTower() {}

CommandTower::CommandTower(int team){
	Name = "Command Tower";
        typeId = COMMANDTOWER;
        Life = 20;
        ATK = 2;
	Range = 5;
	Team= team;
 	if(Team==0)
           direction=0;
        else direction=1;

}
}
