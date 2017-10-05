/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */
#include <iostream>
#include "state.h"

namespace state{
    
    State::State(){
        Element element1, element2;
        addElement(element1);
        addElement(element2);
    }
    
    State::~State(){
        
    }
        void State::addElement(Element element) {
            this->listElement.push_back(element);
            std::cout << "Element ajouté" << std::endl;
            std::cout << "Taille de la liste est: " << listElement.size() << std::endl;
    }

}