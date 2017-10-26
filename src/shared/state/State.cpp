/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */
#include <iostream>
#include "state.h"
#include "State.h"

namespace state{
    
    State::State () {
        
        std::vector<std::vector<Element> > tabElement;
        initTabElement(tabElement);
        
        
	Enutrof enu0(0), enu1(1);
        Sram sram0(0), sram1(1);
        Sacrieur sacri0(0), sacri1(1);
	Eniripsa eni0(0), eni1(1);
        Iop iop0(0), iop1(1);
        
        Minion minion00(0), minion01(0), minion02(0), minion03(0), minion04(0), minion05(0), minion06(0), minion07(0), minion08(0), minion09(0),
                minion10(1), minion11(1), minion12(1), minion13(1), minion14(1), minion15(1), minion16(1), minion17(1), minion18(1), minion19(1);
        
        CommandCenter commandCenter0(0), commandCenter1(1);
        CommandTower commandTower0(-1), commandTower1(-1);
        
        tabElement[0].push_back(enu0);
        tabElement[0].push_back(sram0);
        tabElement[0].push_back(sacri0);
        tabElement[0].push_back(eni0);
        tabElement[0].push_back(iop0);
        
        tabElement[0].push_back(enu1);
        tabElement[0].push_back(sram1);
        tabElement[0].push_back(sacri1);
        tabElement[0].push_back(eni1);
        tabElement[0].push_back(iop1);
        
        getTabSize(tabElement);
        //getTabElement(tabElement);
        
    }
    
    State::~State(){
        
    }
    
    
    
    void State::getTabSize (std::vector<std::vector<Element> > &tab){
        std::cout << "taille table : " << tab.size() << std::endl;
        for (int i = 0; i < (int)tab.size(); i++){
            std::cout << "taille ligne " << i << ": " << tab[i].size() << std::endl;
        }
    }
    
    /*void State::getTabElement ( std::vector<std::vector<Element> > &tab){
        for (int i = 0; i < (int)tab.size(); i++){
            for (int j = 0; j < (int)tab[i].size(); j++){
                std::cout << tab[i][j].getStatus << std::endl;
            }
            std::cout<<" "<<std::endl;
        }
    }*/
    
    void State::initTabElement (std::vector<std::vector<Element> >& tab){
         tab.push_back(std::vector<Element>(0));
         tab.push_back(std::vector<Element>(0));
         tab.push_back(std::vector<Element>(0));
    }
}

