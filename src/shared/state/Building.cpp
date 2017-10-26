/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

#include <iostream>
#include "Building.h"
#include "MobileElement.h"

namespace state {
    Building::Building(int team) : StaticElement() {
        Team = team;
        ATK = 10;
        std::cout << " Building created in team " << team <<" >> ";
    }
    Building::~Building() {}
    
    void Building::Attack(MobileElement &victime){
        std::cout << Name << " attaque " <<  victime.getName() << std::endl;
	victime.getDamage(ATK);
    }
}