/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

#include <iostream>
#include "QG.h"

namespace state {
    QG::QG() : Building() {
        Name = "QG";
        Life = 500;
        std::cout << Name << "created" << std::endl;
    }
    QG::~QG() {}
    
    void QG::getDamage (int damage){
        Life -= damage;
        std::cout << "Un " << Name << " reçoit des dégâts !" << std::endl;
    }
    
    bool QG::isAlive (){
        return Life > 0 ;
    }
}