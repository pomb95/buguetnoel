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
        PosX = 0;
        PosY = 0;
        std::cout << Name <<" created" << std::endl;
    }

    Element::~Element() {}
    
    const std::string& Element::getName() const{
        return this->Name;
    }
}
