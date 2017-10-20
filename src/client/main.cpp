#include <iostream>

// Les lignes suivantes ne servent qu'à vérifier que la compilation avec SFML fonctionne
#include <SFML/Graphics.hpp>

void testSFML() {
    sf::Texture texture;
}

// Fin test SFML

#include "state.h"
//#include "renderer.h"

using namespace std;
using namespace state;

int main(int argc,char* argv[]) 
{	

	if ((argv[1] != NULL) && string(argv[1]) == "state"){
           
	     Enutrof hero1;
             Sram hero2;
             Sacrieur hero3;
	     hero1.Attack(hero2);
             hero3.Attack(hero1);
             QG qg1;

		
}

if ((argv[1] != NULL) && string(argv[1]) == "render"){
           
	    sf::RenderWindow window(sf::VideoMode(512, 256), "Tilemap");

while (window.isOpen())
    {
        // on gère les évènements
        sf::Event event;
        while (window.pollEvent(event))
        {
            if(event.type == sf::Event::Closed)
		
                window.close();
        }

	window.clear();
window.display();	
}
}
      
    return 0;
}
