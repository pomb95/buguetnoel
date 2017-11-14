#include <iostream>

// Les lignes suivantes ne servent qu'à vérifier que la compilation avec SFML fonctionne
#include <SFML/Graphics.hpp>

void testSFML() {
    sf::Texture texture;
}



// Fin test SFML

#include "state.h"
#include "render.h"
#include "engine.h"
#include "ai.h"


using namespace std;
using namespace state;
using namespace render;
using namespace engine;

int main(int argc, char* argv[]) {

    if ((argv[1] != NULL) && string(argv[1]) == "state") {

        State state;
        state.init();

    }

    if ((argv[1] != NULL) && string(argv[1]) == "render") {
        State state;
        state.init();
        Render render;
        render.init(state);

        while (render.window.isOpen()) {
            // on gère les évènements
            sf::Event event;
            while (render.window.pollEvent(event)) {
                if (event.type == sf::Event::Closed)

                    render.window.close();
            }
        }
    }

    if ((argv[1] != NULL) && string(argv[1]) == "engine") {
        std::cout<<"Appuyer sur B pour effectuer une action "<<std::endl;
        State state;
        Render render;
        Engine engine;
        state.init();
        render.init(state);

        state.Update();

        while (render.window.isOpen()) {
            // on gère les évènements
            sf::Event event;
            while (render.window.pollEvent(event)) {
                if (event.type == sf::Event::Closed) {

                    render.window.close();
                }

                if (event.type == sf::Event::KeyPressed) {
                    if (sf::Keyboard::isKeyPressed(sf::Keyboard::B)) {
                        engine::MoveChar command1(1,2);
                        engine.addCommand(command1);
                        engine::MoveChar command4(1,6);
                        engine.addCommand(command4);
                        engine::MoveChar command3(1,4);
                        engine.addCommand(command3);
                        
                         //test pour attack
                        engine::Attack command2(1,2,5); // L'éni attaque le sram

                        engine.addCommand(command2);
                        engine.addCommand(command3);
                         engine.addCommand(command2);
                        engine.addCommand(command3);
                         engine.addCommand(command2);
                        engine.addCommand(command3);
                         engine.addCommand(command2);
                        engine.addCommand(command3);
                        engine.addCommand(command2);
                         engine.addCommand(command3);
                        engine.addCommand(command2);
                         engine.addCommand(command3);
                        engine.addCommand(command2);
                        engine::Attack command5(1,3,5);
                        engine.addCommand(command5);
                        
                         
                        while(!engine.commands.empty()){
                        engine.Update(state);
                        state.Update();
                        render.Update(state);
                        
                        
                        }
                        
                      
                        
                    }

                } 
                
            }
        }


    }

if ((argv[1] != NULL) && string(argv[1]) == "randomAi") {
        std::cout<<"Appuyer sur B pour effectuer une action "<<std::endl;
        State state;
        Render render;
        Engine engine;
        state.init();
        render.init(state);
        ai::RandomAi bot1(0);
        ai::RandomAi bot2(1);
        bot1.init();
        bot2.init();
        state.Update();
        

        while (render.window.isOpen()) {
            // on gère les évènements
            sf::Event event;
            while (render.window.pollEvent(event)) {
                if (event.type == sf::Event::Closed) {

                    render.window.close();
                }

                if (event.type == sf::Event::KeyPressed) {
                    if (sf::Keyboard::isKeyPressed(sf::Keyboard::B)) {
                       
                        
                        
                         
                       
                        bot1.play(engine,engine.char_sel,state);
                        bot2.play(engine,engine.char_sel,state);
                        engine.Update(state);
                        state.Update();
                        render.Update(state);
                        
                        
                        
                        
                      
                        
                    }

                } 
               if(state.fin==1)
               {
                   State state;
        Render render;
        Engine engine;
        state.init();
        render.init(state);
        ai::RandomAi bot1(0);
        ai::RandomAi bot2(1);
        bot1.init();
        bot2.init();
        state.Update();
                   state.fin=0;
               }
            }
        }


    }

    return 0;
}

