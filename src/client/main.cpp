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
    cout << "It works !" << endl;
	if ((argv[1] != NULL) && string(argv[1]) == "state"){
            Enutrof hero1;
            Sram hero2;
            hero1.Attack(hero2);
            hero1.Attack(hero2);
	}
    return 0;
}
