/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

#include <iostream>
#include "Minion.h"

namespace state {
    Minion::Minion() : MobileElement() {
        Name = "Minion";
        Life = 50;
        Range = 1;
        ATK = 5;
        typeId = MINION;
        std::cout << " Minion Created" << std::endl;
    }
    Minion::~Minion() {}
}
