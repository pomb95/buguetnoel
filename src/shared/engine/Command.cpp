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
   
        if(direction==6)
         { std::cout << state.list_element[character].getName() << " se déplace à droite" << std::endl;
                   state.list_element[character].setPosX(state.list_element[character].getPosX() + 28);
                 
        }
        else if(direction==8){ std::cout << state.list_element[character].getName() << " se déplace en haut" << std::endl;
                   state.list_element[character].setPosY(state.list_element[character].getPosY() - 28);
                  
        }
        else if(direction==2){ std::cout << state.list_element[character].getName() << " se déplace à bas" << std::endl;
                   state.list_element[character].setPosY(state.list_element[character].getPosY() + 28);
                  
        }
        else if(direction==4){ std::cout << state.list_element[character].getName() << " se déplace à bas" << std::endl;
                   state.list_element[character].setPosX(state.list_element[character].getPosX() - 28);
                   
        }else{std::cout<<"cette direction n'existe pas :)"<<std::endl;
            
        
                 
    }
    }
}