/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */
#include <iostream>
#include "state.h"

namespace state{
    
    State::State(){
	Enutrof hero1;
        Sram hero2;
        Sacrieur hero3;
	hero1.Attack(hero2);
        hero3.Attack(hero1);
        Building bat;
        CommandTower com;
        CommandCenter QG1;
        Minion minion1;
    }
    
    State::~State(){
        
    }
        void State::addElement(Element element) {
            this->listElement.push_back(element);
            std::cout << "Element ajouté" << std::endl;
            std::cout << "Taille de la liste est: " << listElement.size() << std::endl;
    }

}
