/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */
#include <iostream>
#include "Sram.h"

namespace state {
    Sram::Sram(){
        m_Name = "Sram";
	std::cout <<"C'est un " << m_Name << std::endl;
    }
    
    Sram::~Sram(){
        
    }
}
