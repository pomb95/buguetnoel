/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */
#include <iostream>
#include "Enutrof.h"

namespace state {
    Enutrof::Enutrof(){
        m_Name = "Enutrof";
	std::cout <<"C'est un " << m_Name << std::endl;
    }
    
    Enutrof::~Enutrof(){
        
    }
}
