/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */
#include <iostream>
#include "state.h"

namespace state{
    
    State::State(){ 
        path="res/level3.png";
        enable_render=0;
    }
    
    State::~State(){
        
    }
    
    void State::init(){
        
        
        Iop hero1;
        list_element.push_back(hero1);
        
        Eniripsa hero2;
        list_element.push_back(hero2);
        
        Sram hero3;
        list_element.push_back(hero3);
        
        Enutrof hero4;
        list_element.push_back(hero4);
        
        Sacrieur hero5;
        list_element.push_back(hero5);
        
        Iop hero6;
        list_element.push_back(hero6);
        
        CommandTower tour1;
        list_element.push_back(tour1);
        
        CommandTower tour2;
        list_element.push_back(tour2);
        
        CommandCenter center1;
        list_element.push_back(center1);
        
        CommandCenter center2;
        list_element.push_back(center2);
    }
    
    std::vector<Element> State::getListeElement() {
        return list_element;
    }
    
    void state::State::Update(){
        
      /*  std::cout <<"perso 1 : "<< list_element[0].getPosX() <<","<< list_element[0].getPosY() << std::endl;
    std::cout <<"perso 2 : "<< list_element[1].getPosX() <<","<< list_element[1].getPosY() << std::endl;
    std::cout <<"perso 3 : "<< list_element[2].getPosX() <<","<< list_element[2].getPosY() << std::endl;
    std::cout <<"perso 4 : "<< list_element[3].getPosX() <<","<< list_element[3].getPosY() << std::endl;
    std::cout <<"perso 5 : "<< list_element[4].getPosX() <<","<< list_element[4].getPosY() << std::endl;
    std::cout <<"perso 6 : "<< list_element[5].getPosX() <<","<< list_element[5].getPosY() << std::endl;*/
    }

    
}
