/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */
#include <iostream>
#include "state.h"

namespace state{
    
    State::State(){
	/*Enutrof hero1;
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
        hero2.getStatus();*/
        
       
        
        CommandTower tour1;
        list_element.push_back(tour1);
        
        CommandTower tour2;
        list_element.push_back(tour2);
        
        CommandTower tour3;
        list_element.push_back(tour3);
        
        CommandTower tour4;
        list_element.push_back(tour4);
        
   
        CommandCenter center1;
        list_element.push_back(center1);
        
        CommandCenter center2;
        list_element.push_back(center2);
        
         Iop hero1;
        list_element.push_back(hero1);
        
        Eniripsa hero2;
        list_element.push_back(hero2);
        
        Sram hero3;
        list_element.push_back(hero3);
        
        Enutrof hero4;
        list_element.push_back(hero4);
        
    
        
        
        
        
        
        
        
        
    }
    
    State::~State(){
        
    }
    
    
    
    
}