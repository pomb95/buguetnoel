/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */
#include <iostream>
#include "Sram.h"

namespace state {
    Sram::Sram(int team) : Hero(team){
        Name = "Sram";
        Range = 7;
        ATK = 10;
	std::cout << Name <<" created" << std::endl;
    }
    
    Sram::~Sram(){
        
    }
}
