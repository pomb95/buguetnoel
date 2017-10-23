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
        hero1.getStatus();
        CommandTower com;
        CommandCenter QG1;
        Minion minion1;
        minion1.Attack(QG1);
        QG1.getStatus();
        QG1.Attack(hero2);
        hero2.getStatus();
        
    }
    
    State::~State(){
        
    }
    
    
    
    
}
