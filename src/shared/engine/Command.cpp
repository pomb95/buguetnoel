/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

#include "Command.h"
#include "CheckAround.h"
#include <iostream>


engine::Command::Command() {}
engine::Command::~Command() {}
void engine::Command::execute (state::State& state){
    if(Id==1){
		std::cout << "position actuelle : " << state.list_element[character].getPosX() << ", " <<state.list_element[character].getPosY() << std::endl;
   
        	if(direction==6){ std::cout << state.list_element[character].getName() << " veut se déplacer vers la droite" << std::endl;
			  	 if  ( state.list_element[character].getPosX()==672){
				       std::cout << "déplacement pas possible"<<std::endl;}

                  		 else {std::cout << state.list_element[character].getName() << " se déplace : droite" << std::endl;
				       state.list_element[character].setPosX(state.list_element[character].getPosX() + 28);}
                 
                                 }

                else if(direction==8){ std::cout << state.list_element[character].getName() << " veut se déplacer vers le haut" << std::endl;
				if  ( state.list_element[character].getPosY()==0){
				      std::cout << "déplacement pas possible"<<std::endl;}

				else{ std::cout << state.list_element[character].getName() << " se déplace : haut" << std::endl;
				      state.list_element[character].setPosY(state.list_element[character].getPosY() - 28);}
                  
                              }

                else if(direction==2){ std::cout << state.list_element[character].getName() << " veut se déplacer en bas" << std::endl;
				if  ( state.list_element[character].getPosY()==672){
				      std::cout << "déplacement pas possible"<<std::endl;}

				else{ std::cout << state.list_element[character].getName() << " se déplace : bas" << std::endl;
                   		      state.list_element[character].setPosY(state.list_element[character].getPosY() + 28);}
                  
                              }

                else if(direction==4){ std::cout << state.list_element[character].getName() << " veut se déplacer à gauche" << std::endl;
				if  ( state.list_element[character].getPosX()==0){
				      std::cout << "déplacement pas possible"<<std::endl;}

				else{ std::cout << state.list_element[character].getName() << " se déplace : gauche" << std::endl;
                   		      state.list_element[character].setPosX(state.list_element[character].getPosX() - 28);}
                   
        }else{
            std::cout<<"cette direction n'existe pas :)"<<std::endl;
        }
        
        std::cout << "new position : " << state.list_element[character].getPosX() << ", " << state.list_element[character].getPosY() << std::endl;
                    
    
    }
	if(Id==2){
            std::cout << "Nous sommes dan l'attaque" << std::endl;
        }
    
        if(Id == 3){
            std::cout << "Detection des éléments..." << std::endl;
            int increment = 1;
            int y2 = 0;
            int pos = state.list_element[character].getPosX();
            int r = state.list_element[character].getRange();
            for (int x = pos-r; x < pos + r; x += 28){
                for (int y = -y2; y < y2; y+=28){
                    
                }
            }
        }
}

int engine::Command::getAttaquant() const {
    return attaquant;
}

int engine::Command::getCharacter() const {
    return character;
}

int engine::Command::getDegat() const {
    return degat;
}

int engine::Command::getDirection() const {
    return direction;
}

int engine::Command::getId() const {
    return Id;
}

int engine::Command::getVictime() const {
    return victime;
}

void engine::Command::setAttaquant(int attaquant) {
    this->attaquant =  attaquant;
}

void engine::Command::setCharacter(int character) {
    this->character = character;
}

void engine::Command::setDegat(int degat) {
    this->degat = degat;
}

void engine::Command::setDirection(int direction) {
    this->direction = direction;
}

void engine::Command::setId(int Id) {
    this->Id = Id;
}

void engine::Command::setVictime(int victime) {
    this->victime = victime;
}



