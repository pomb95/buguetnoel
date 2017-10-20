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
        std::cout << Name << " created" << std::endl;
    }
    CommandTower::~CommandTower() {}
}
