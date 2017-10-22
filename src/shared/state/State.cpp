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
        void State::addElement(Element element) {
            this->listElement.push_back(element);
            std::cout << "Element ajouté" << std::endl;
            std::cout << "Taille de la liste est: " << listElement.size() << std::endl;
        }
        
        void State::addHero(Hero hero) {
            this->listHero.push_back(hero);
            std::cout << "Element ajouté" << std::endl;
            std::cout << "Taille de la liste est: " << listHero.size() << std::endl;
        }
        
        void State::addMinion (Minion minion){
            this->listMinion.push_back(minion);
            std::cout << "Element ajouté" << std::endl;
            std::cout << "Taille de la liste est: " << listMinion.size() << std::endl;
        }
        
        void State::addBuilding (Building building){
            this->listBuilding.push_back(building);
            std::cout << "Element ajouté" << std::endl;
            std::cout << "Taille de la liste est: " << listBuilding.size() << std::endl;
        }
}
