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
        ATK = 2;
	    Life = 10;
	    Alive = 1; // en vie
        typeId = ENI;
        Movement=3;

       // std::cout << Name <<" created" << std::endl;
    }

     Eniripsa::Eniripsa(int team) : Hero() {
        Name = "Eniripsa";
        Range = 5;
        ATK = 2;
     	Life = 10;
    	Alive = 1; // en vie
        typeId = ENI;
        Team=team;
        Movement=3;
        if(Team==0)
            direction=0;
        else direction=1;

       // std::cout << Name <<" created" << std::endl;
    }
    Eniripsa::~Eniripsa() {}
}
