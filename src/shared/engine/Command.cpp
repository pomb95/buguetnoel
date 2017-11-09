/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

#include "Command.h"
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
	if(Id==2){std::cout << "Nous sommes dan l'attaque" << std::endl;}
}
