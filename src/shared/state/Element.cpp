/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */
#include <iostream>
#include "Element.h"

namespace state {
    Element::Element(){
        Name = "Element";
        std::cout << Name <<" created" << std::endl;
    }

    Element::~Element() {}
    
    const std::string& Element::getName() const{
        return this->Name;
    }
   /* void Element::getDamage(int damage) {
        m_Life -= damage;
        std::cout << "Un " << m_Name << " reçoit des dégâts !" << std::endl;
        if (!isAlive()) { std::cout << "Un " << m_Name << " est mort :(" << std::endl;}
    }
     
    void Element::Attack(Element& other){
        std::cout << "un " << m_Name <<" attaque !" << std::endl;
        other.getDamage(m_ATK);             
    }
       
    bool Element::isAlive() {
            return m_Life > 0 ;
    }*/
}
