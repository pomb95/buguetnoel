/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

#include <iostream>
#include "Eniripsa.h"

namespace state {
    Eniripsa::Eniripsa() : Hero() {
        Name = "Eniripsa";
        Range = 5;
        ATK = 10;
        std::cout << Name <<" created" << std::endl;
    }
    Eniripsa::~Eniripsa() {}
}