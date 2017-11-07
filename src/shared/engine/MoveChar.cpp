#include "MoveChar.h"
#include <iostream>
#include "Command.h"
#include <state/MobileElement.h>

engine::MoveChar::MoveChar(int c, int d) : character(c), direction(d){
    
}

engine::MoveChar::~MoveChar(){
    
}

void engine::MoveChar::execute (state::State& state){
    state::Element perso = state.getListeElement()[character];
    switch (direction) {
        case 6 : { std::cout << perso.getName() << " se déplace à droite" << std::endl;
                   perso.setPosX(perso.getPosX() + 28);
                   break;
        }
        case 8 : { std::cout << perso.getName() << " se déplace en haut" << std::endl;
                   perso.setPosY(perso.getPosY() - 28);
                   break;
        }
        case 2 : { std::cout << perso.getName() << " se déplace à bas" << std::endl;
                   perso.setPosY(perso.getPosY() + 28);
                   break;
        }
        case 4 : { std::cout << perso.getName() << " se déplace à bas" << std::endl;
                   perso.setPosX(perso.getPosX() - 28);
                   break;
        }
        default:
            break;
                 
    }
}