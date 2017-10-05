/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */
#include <iostream>
#include "Hero.h"

namespace state {
    Hero::Hero(){
        m_Name = "Hero";
        m_Life = 10;
        m_ATK = 5;
        std::cout << "C'est un " <<m_Name << std::endl;
    }
    
    Hero::~Hero(){
    
    }
       
   
}
