/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */
#include <iostream>
#include "Enutrof.h"

namespace state {
    Enutrof::Enutrof(){
        Name = "Enutrof";
        Life = 10;
        Range = 5;
        Movement = 3;
        ATK = 5;
        typeId = ENU;
	//std::cout << Name <<" created" << std::endl;
    }

    Enutrof::Enutrof(int team ){
        Name = "Enutrof";
        Life = 10;
        Range = 5;
        Movement = 3;
        ATK = 5;
        typeId = ENU;
        Team=team;
        if(Team==0)
            direction=0;
        else direction=1;
	//std::cout << Name <<" created" << std::endl;
    }

    Enutrof::~Enutrof(){

    }
}
