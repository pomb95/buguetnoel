/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

#include <iostream>
#include "Building.h"
#include "MobileElement.h"

namespace state {
    Building::Building() : StaticElement() {
        std::cout << "Building created" << std::endl;
    }
    Building::~Building() {}
       
}