/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

#include <iostream>
#include "Iop.h"

namespace state {
    Iop::Iop() : Hero() {
        Name = "Iop";
        Life = 75;
        Range = 3;
        ATK = 20;
        typeId = IOP;
        //std::cout << Name <<" created" << std::endl;
    }
    Iop::~Iop() {}
}