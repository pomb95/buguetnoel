#include <iostream>
#include <SFML/Graphics.hpp>
#include <thread>
#include <mutex>
#include "state.h"
#include "render.h"
#include "engine.h"
#include "ai.h"
#include "json/json.h"
#include <fstream>
#include <unistd.h>

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
                      if(tour < 40){

                          if(event.type == sf::Event::KeyPressed) {
                              if(sf::Keyboard::isKeyPressed(sf::Keyboard::B)) {
                        	         bot1.play(engine,engine.char_sel,state);
                        	         bot2.play(engine,engine.char_sel,state);
                        	         engine.Update(state);
                       	 	         state.Update();
                        	         render.Update(state);
                                         listState.push_back(state);
                                     std::cout << "Epoque : " << tour << std::endl;
                                     tour ++;
                                     tour2++;
                                 }
                         }
                       }
                     if( tour >= 40 && tour2 > 0){//rollback sur les tours precendents

                          if(event.type == sf::Event::KeyPressed) {
                              std::cout << "Rollback" << std::endl;
                              if(sf::Keyboard::isKeyPressed(sf::Keyboard::B)) {
                                     std::cout << "Epoque : " << tour2 << std::endl;
                        	     engine.Update(state, 1);
                                     state.Update();
                                     render.Update(state);

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

    if ((argv[1] != NULL) && string(argv[1]) == "deep_ai") {
	       std::cout<<"Appuyer sur B pour effectuer une action "<<std::endl;

           State state;
	       Render render;
	       Engine engine;
	       state.init();
           render.init(state);
           ai::MinMax bot1(1);
           ai::MinMax bot0(0);
	       bot1.init();
           bot0.init();

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
					                 bot0.play(engine,engine.char_sel,state);
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

    if ((argv[1] != NULL) && string(argv[1]) == "thread") {
	       std::cout<<"Appuyer sur B pour effectuer une action "<<std::endl;
	       State state;
	       Render render;
	       Engine engine;
	       thread th(&engine::Engine::UpdateTh, &engine, std::ref(state));//thread de l'Engine
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
                                 		{
                                           	 std::lock_guard<std::mutex> lock(engine.mutex);
				                 if (engine.fin_tour) engine.fin_tour = false;
				                 	bot1.play(engine,engine.char_sel,state);
				    	         	bot2.play(engine,engine.char_sel,state);
				                 if (!engine.fin_tour) 
						      engine.fin_tour = true;
				        }

                                 	if (engine.engine_update){
                                     		state.Update();
                                     		render.Update(state);
                                     		if(engine.engine_update) 
							engine.engine_update = false;
                                 	}

			         }
		         }

                if(state.fin==1){
               	     state.fin=0;
                     render.window.close();
		}
                 }
          	}
       th.join();
    }


if ((argv[1] != NULL) && string(argv[1]) == "play") {
	State state;
	Engine engine;
	state.init();
	ai::HeuristicAi bot1(0);
	ai::HeuristicAi bot2(1);
	bot1.init();
	bot2.init();
	state.Update();
	ifstream file; 				//Creation du fichier texte
        Json::Value replay;			// Creation d'une variable JSON replay (  où est stocké la totalité des commandes de la partie)
	Json::Value command;			// creation variable JSON command ( stocke une commandes)
	Command com;				
        file.open("replay.txt"); 		//ouverture du fichier texte où les commandes de la partie JSON sont stockées.
        file >> replay;				
        file.close();
        std::cout<<"*****New Play ******"<<std::endl;
	

	
            //On recupere les positions des joueurs
        Tiles tile;
        tile.convert(state);
        for (int i = 0; i<state.nb_hero; i++) {
             if((state.list_element[i].getTypeId()==7)||(state.list_element[i].getTypeId()==6)||(state.list_element[i].getTypeId()==8)||(state.list_element[i].getTypeId()==9)||(state.list_element[i].getTypeId()==10)){
                
                state.list_element[i].setPosX(static_cast<int> (tile.list_pos_hero[i].x));
                state.list_element[i].setPosY(static_cast<int> (tile.list_pos_hero[i].y));
             
             }
	}

                       
        for(unsigned i = 0 ;i<replay.size();i++ ){
                 std::cout<<"*****New Turn ******"<<std::endl;
                 for (unsigned j = 0;j<replay[i].size();j++){
                    	Json::Value command;
                    	command=replay[i][j];
                    	com.deserialize(command);  // deserialize les commandes
                    	engine.addCommand(com);     // on execute une commande
                     	engine.Update(state);	   // on update l'etat.
                       	state.Update();
			usleep(50000);
		   
               		
                        
				
		 } 
                       
        }
  }
    return 0;
}

