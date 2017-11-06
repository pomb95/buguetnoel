#include <iostream>

// Les lignes suivantes ne servent qu'à vérifier que la compilation avec SFML fonctionne
#include <SFML/Graphics.hpp>

void testSFML() {
    sf::Texture texture;
}

// Fin test SFML

#include "state.h"
#include "render.h"
#include "render/Tiles.h"

using namespace std;
using namespace state;
using namespace render;

int main(int argc,char* argv[]) 
{	

	if ((argv[1] != NULL) && string(argv[1]) == "state"){
           
            State state;
            
           
        }

if ((argv[1] != NULL) && string(argv[1]) == "render"){
    State state; 
    Render render;
    render.init(state);
    Tiles tile;
    tile.getListPosHero();
while (render.window.isOpen())
    {
        // on gère les évènements
        sf::Event event;
        while (render.window.pollEvent(event))
        {
            if(event.type == sf::Event::Closed)
		
                render.window.close();
        }

		
}
}
      
    return 0;
}
