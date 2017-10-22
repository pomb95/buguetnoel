/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

#include <iostream>
#include "MobileElement.h"
#include "CommandCenter.h"

namespace state{
    MobileElement::MobileElement() {
        Movement = 5;
        std::cout << "Mobile Element created" << std::endl;
    }
    MobileElement::~MobileElement() {}

    void MobileElement::Attack(MobileElement &victime){
        std::cout << Name << " attaque " <<  victime.getName() << std::endl;
	victime.getDamage(ATK); 
    }
    
    void MobileElement::Attack (CommandCenter &victime){
        std::cout << Name << " attaque " <<  victime.getName() << std::endl;
	victime.getDamage(ATK); 
    }

    void MobileElement::getDamage(int damage) {
        Life -= damage;
        std::cout << "Un " << Name << " reçoit des dégâts !" << std::endl;
        //if (!isAlive()) { std::cout << "Un " << Name << " est mort :(" << std::endl;}
    }

    bool MobileElement::isAlive() {
        return Life > 0 ;
    }
	
}
