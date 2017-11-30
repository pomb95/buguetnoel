/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

#include <iostream>
#include "Sacrieur.h"

namespace state {
    Sacrieur::Sacrieur() : Hero() {
        Name = "Sacrieur";
        Life = 150;
        Range = 1;
        ATK = 10;
        typeId = SACRI;
        //std::cout << Name << " created" << std::endl;
    }
    Sacrieur::~Sacrieur() {}
}
