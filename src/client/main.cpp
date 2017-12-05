#include <iostream>
#include <SFML/Graphics.hpp>
#include "state.h"
#include "render.h"
#include "engine.h"
#include "ai.h"

// Les lignes suivantes ne servent qu'à vérifier que la compilation avec SFML fonctionne
void testSFML() {
    sf::Texture texture;
}

// Fin test SFML


using namespace std;
using namespace state;
using namespace render;
using namespace engine;

int main(int argc, char* argv[]) {

    if ((argv[1] != NULL) && string(argv[1]) == "state") {
	 State state;
         state.init();
    }

    if ((argv[1] != NULL) && string(argv[1]) == "render") {   		   //Livrable 2.1
         State state;
         state.init();
         Render render;
         render.init(state);

         while (render.window.isOpen()) {                                  // on gère les évènements
                sf::Event event;
                while (render.window.pollEvent(event)) {
                       if (event.type == sf::Event::Closed)		   // On teste la fermeture de la fenetre
                           render.window.close();
                }
         }
    }

    if ((argv[1] != NULL) && string(argv[1]) == "engine") {                //Livrable 2.2
        std::cout<<"Appuyer sur B pour effectuer une action "<<std::endl;
        State state;
        Render render;
        Engine engine;
        state.init();
        render.init(state);
        state.Update();

        while (render.window.isOpen()) {
               sf::Event event;
               while (render.window.pollEvent(event)) {
                      if (event.type == sf::Event::Closed) {
                          render.window.close();
                      }

                      if (event.type == sf::Event::KeyPressed) {
                          if (sf::Keyboard::isKeyPressed(sf::Keyboard::B)) {              //on teste la pression du bouton B.
                              engine::MoveChar command1(1,2);                             // On crée la commande "deplacement bas au héro 1
                              engine.addCommand(command1);			          // On ajoute la commande a éxécuter
                              engine::MoveChar command4(1,6);				  // Déplacement droite
		              engine.addCommand(command4);
			      engine::MoveChar command3(1,4);                             // déplacement gauche
		              engine.addCommand(command3);
			      engine::Attack command2(1,2);           // L'éni attaque le sram          //test pour attack
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
                              engine::Attack command5(1,3);            // le héros 1 attaque le personnage 3 , de 5 dégats.
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

    if ((argv[1] != NULL) && string(argv[1]) == "random_ai") {
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

               	      if(state.fin==1){
                         state.fin=0;
                         render.window.close();
                      }
                }
         }
    }



    if ((argv[1] != NULL) && string(argv[1]) == "heuristic_ai") {
	std::cout<<"Appuyer sur B pour effectuer une action "<<std::endl;
	State state;
	Render render;
	Engine engine;
	state.init();
	render.init(state);
	ai::HeuristicAi bot1(0);
	ai::HeuristicAi bot2(1);
	bot1.init();
	bot2.init();
	state.Update();


        while (render.window.isOpen()) {
               sf::Event event;
               while (render.window.pollEvent(event)) {

		      if(event.type == sf::Event::Closed) {
                         render.window.close();
                      }

                      if(event.type == sf::Event::KeyPressed) {
                          if(sf::Keyboard::isKeyPressed(sf::Keyboard::B)) {
                        	bot1.play(engine,engine.char_sel,state);
                        	bot2.play(engine,engine.char_sel,state);
                        	engine.Update(state);
                       	 	state.Update();
                        	render.Update(state);
			  }
		       }

               	      if(state.fin==1){
               		 state.fin=0;
                         render.window.close();
		      }
                 }
          }


    }

    if ((argv[1] != NULL) && string(argv[1]) == "rollback") {
	       std::cout<<"Appuyer sur B pour effectuer une action "<<std::endl;
           int tour = 0;
           int tour2 = 0;
           std::vector<state::State> listState;
           State state;
	       Render render;
	       Engine engine;
	       state.init();
           //state.addState(state.clone());
           listState.push_back(state);
           render.init(state);
           ai::HeuristicAi bot1(0);
           ai::HeuristicAi bot2(1);
           bot1.init();
           bot2.init();
           state.Update();
           sf::Clock temps;


        while (render.window.isOpen()) {
               sf::Event event;
               while (render.window.pollEvent(event)) {

		      if(event.type == sf::Event::Closed) {
                         render.window.close();
              }
                      if(tour < 20){
                     //10 premiers coups
                          if(event.type == sf::Event::KeyPressed) {
                              if(sf::Keyboard::isKeyPressed(sf::Keyboard::B)) {
                        	         bot1.play(engine,engine.char_sel,state);
                        	         bot2.play(engine,engine.char_sel,state);
                        	         engine.Update(state);
                       	 	         state.Update();
                        	         render.Update(state);
                                         listState.push_back(state);
                                     //state.addState(state.clone());
                                     //listState.push_back(state);
                                     std::cout << "Epoque : " << tour << std::endl;
                                     tour ++;
                                     tour2++;
                                 }
                         }
                       }
                     if( tour >= 20 && tour2 > 1){//rollback sur les tours precendents

                          if(event.type == sf::Event::KeyPressed) {
                              std::cout << "Rollback" << std::endl;
                              if(sf::Keyboard::isKeyPressed(sf::Keyboard::B)) {
                                     std::cout << "Epoque : " << tour2 << std::endl;
                        	         engine.Update(state, 1);
                                     state.Update();
                                     render.Update(state);

                        	         //bot1.play(engine,engine.char_sel,state.list_state[tour2]);
                        	         //bot2.play(engine,engine.char_sel,state.list_state[tour2]);
                        	         //engine.Update(listState[0]);
                                      std::cout << "Rollback" << std::endl;
                                     render.Update(listState[tour2-1]);
                                     tour2--;
                               }
                           }
		              }

               	      if(state.fin==1){
               		 state.fin=0;
                         render.window.close();
		      }
                 }
          }


    }

    else{
        std::cout << "Commande inconnue, essayez :" << std::endl;
        std::cout << "  state" << std::endl;
        std::cout << "  render" << std::endl;
        std::cout << "  engine" << std::endl;
        std::cout << "  random_ai" << std::endl;
        std::cout << "  heuristic_ai"<<std::endl;
        std::cout << "  rollback"<<std::endl;

    }

    return 0;
}
