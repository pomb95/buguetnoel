/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */
#include <iostream>
#include "Sram.h"

namespace state {
    Sram::Sram(){
        Name = "Sram";
        Range = 5;
        ATK = 5;
	Life = 10;
	Alive = 1;
        typeId = SRAM;
	//std::cout << Name <<" created" << std::endl;
    }
     Sram::Sram(int team){
        Name = "Sram";
        Range = 5;
        ATK = 5;
	Life = 10;
	Alive = 1;
        typeId = SRAM;
        Team=team;
        if(Team==0)
            direction=0;
        else direction=1;
	//std::cout << Name <<" created" << std::endl;
    }

    Sram::~Sram(){

    }
}
