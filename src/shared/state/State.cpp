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
        
    
        
        
        
        
<<<<<<< HEAD
=======
        Iop hero6;
        list_iop.push_back(hero6);
	
	Sram hero7;
        list_sram.push_back(hero7);
>>>>>>> 07717267373da672ce6434b69cf43e6ec8e2b378
        
        CommandCenter Center1;
	list_CommandCenter.push_back(Center1);
	
	CommandCenter Center2;
	list_CommandCenter.push_back(Center2);

	CommandTower Tower1;
	list_CommandTower.push_back(Tower1);

	CommandTower Tower2;
	list_CommandTower.push_back(Tower2);
        
        
    }
    
    State::~State(){
        
    }
    
    
    
    
}
