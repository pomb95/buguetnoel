/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */
#include <iostream>
#include "Hero.h"

namespace state {
    Hero::Hero(int team) : MobileElement(team) {
        Name = "Hero";
        std::cout << Name <<" created >> ";
    }
    
    Hero::~Hero(){
    
    } 

   
}
