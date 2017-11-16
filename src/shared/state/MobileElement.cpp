/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

#include <iostream>
#include "MobileElement.h"
#include "CommandCenter.h"

namespace state{
    MobileElement::MobileElement() : Element() {
        Team = 0;
        Movement = 3;
        Life = 10;
        ATK = 10;
        Range = 5;
        //std::cout << " Mobile Element created >> ";
    }
    MobileElement::~MobileElement() {}

    /*void MobileElement::Attack(MobileElement &victime){
        std::cout << Name << " attaque " <<  victime.getName() << std::endl;
	victime.getDamage(ATK); 
    }
    
    void MobileElement::Attack (CommandCenter &victime){
        std::cout << Name << " attaque " <<  victime.getName() << std::endl;
	victime.getDamage(ATK); 
    }

    void MobileElement::getDamage(int damage) {
        Life -= damage;
        if (Life < 0) Life = 0;
        std::cout << "Un " << Name << " reçoit des dégâts !" << std::endl;
        if (!isAlive()) std::cout << "Un " << Name << " est mort :(" << std::endl;
    }*/

    //bool MobileElement::isAlive() {
      //  return Life > 0 ;
   // }
    
    void MobileElement::getStatus() {
        std::cout << " " << std::endl;
        std::cout << "Name : " << Name << std::endl;
        std::cout << "TypeId : " << typeId << std::endl;
        std::cout << "PosX : " << PosX << std::endl;
        std::cout << "PosY : " << PosY << std::endl;
        std::cout << "Team : " << Team << std::endl;
        std::cout << "ATK : " << ATK << std::endl;
        std::cout << "Range : " << Range << std::endl;
        std::cout << "Movement : " << Movement << std::endl;
        std::cout << "Life : " << Life << std::endl;
        //std::cout << "Etat : " << isAlive() << std::endl;
        std::cout << " " << std::endl;
    }
    
    
   
  
	
}
