#include <iostream>

// Les lignes suivantes ne servent qu'à vérifier que la compilation avec SFML fonctionne
#include <SFML/Graphics.hpp>

void testSFML() {
    sf::Texture texture;
}

// Fin test SFML

#include "state.h"

using namespace std;
using namespace state;

int main(int argc,char* argv[]) 
{	

	if ((argv[1] != NULL) && string(argv[1]) == "state"){
           
	    State state;
            state.listElement[0].Attack(state.listElement[1]);
            state.listElement[0].Attack(state.listElement[1]);
	}
    return 0;
}
