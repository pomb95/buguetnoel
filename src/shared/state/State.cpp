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
        enable_state=0;
        nb_hero=0;
    }
    
    State::~State(){
        
    }
    
    void State::init(){
        
        
        Iop hero1;
        this->addElement(hero1);
        
        Eniripsa hero2;
        this->addElement(hero2);
        
        Sram hero3;
        this->addElement(hero3);
        
        Enutrof hero4;
        this->addElement(hero4);
        
        Sacrieur hero5;
        this->addElement(hero5);
        
        Iop hero6;
        this->addElement(hero6);
        
        CommandTower tour1;
        this->addElement(tour1);
        
        CommandTower tour2;
        this->addElement(tour2);
        
        CommandCenter center1;
        this->addElement(center1);
        
        CommandCenter center2;
        this->addElement(center2);
    }
    
    std::vector<Element> State::getListElement() {
        return list_element;
    }
    
    void state::State::Update(){
        if(enable_state==1){
        for (int i = 0; i<nb_hero; i++) {
            if(list_element[i].Alive==1){
                if(list_element[i].getLife()==0){
                    list_element[i].Alive=0;
                 std::cout << list_element[i].getName() << " est mort." <<std::endl;
                }
            }
        }
        enable_state=0;
        enable_render=1;
         std::cout <<" State ::: On a notifié au rendu que l'état a changé et au moteur que les modifications ont été effectué "<<std::endl;
        }
    }
    void state::State::addElement(state::Element element){
   
    if((element.getTypeId()==7)||(element.getTypeId()==6)||
                    (element.getTypeId()==8)||(element.getTypeId()==9)||(element.getTypeId()==10)){
                
        nb_hero++;
        list_element.push_back(element);
        
        }
    else
        {
         list_element.push_back(element);
        }
    
    }
    
}
