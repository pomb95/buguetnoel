/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

#include <iostream>
#include "Eniripsa.h"

namespace state {
    Eniripsa::Eniripsa(int team) : Hero(team) {
        Name = "Eniripsa";
        Range = 5;
        ATK = 10;
        typeId = ENI;
        std::cout << Name <<" created" << std::endl;
    }
    Eniripsa::~Eniripsa() {}
}