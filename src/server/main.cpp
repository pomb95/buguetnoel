#include <iostream>
#include "state.h"
#include "engine.h"
#include <SFML/Graphics.hpp>
#include "ai.h"
#include <unistd.h>
#include "json/json.h"
#include <iostream>
#include <fstream>
#include "render.h"

using namespace std;
using namespace state;
using namespace engine;
using namespace render;



int main (int argc, char* argv[]){
 if ((argv[1] != NULL) && string(argv[1]) == "record") {
	State state;
	Engine engine;
        Render render;
	state.init();
	ai::HeuristicAi bot1(0);
	ai::HeuristicAi bot2(1);
	bot1.init();
	bot2.init();
	state.Update();
	ofstream file;            //Creation d'un fichier texte 
	Json::Value replay;	  // Creation d'une variable JSON replay ( stocke la totalité des commandes de la partie)
	Json::Value command;      // creation variable JSON command ( stocke une commandes)
        Json::Value tour;         // Creation variable JSON tour ( stocke les commands d'un tour)
	Command record;		  // Creation d'une commande record ( permet d'obtenir les caractéristiques de chaque commande jouée)
        int count = 0;
        
        //On recupere les positions des joueurs
        Tiles tile;
        tile.convert(state);
        for (int i = 0; i<state.nb_hero; i++) {
             if((state.list_element[i].getTypeId()==7)||(state.list_element[i].getTypeId()==6)||(state.list_element[i].getTypeId()==8)||(state.list_element[i].getTypeId()==9)||(state.list_element[i].getTypeId()==10)){
                
                state.list_element[i].setPosX(static_cast<int> (tile.list_pos_hero[i].x));
                state.list_element[i].setPosY(static_cast<int> (tile.list_pos_hero[i].y));
             
             }
	}
        
        std::cout<<"*****New Play ******"<<std::endl;
	std::cout<<"*****New Turn ******"<<std::endl;

	while(state.fin !=1){
            //on recupere les informations de chaque héros
		if (state.list_element[engine.char_sel].getTeam()==0){
                     record = bot1.play(engine,engine.char_sel,state);   
                }
                else{ record = bot2.play(engine,engine.char_sel,state);
                        	
                }
                       
                       
                engine.Update(state);	
               	state.Update();
		usleep(50000);
                command = record.serialize();  // on stocke dans command , la commande utilisé serializée
                count = count +1;
               
//Si la partie est finie
	        if(state.fin==1){		
                   tour.append(command);      // on stocke dans tour, la totalité des commandes utilisées dans le tour
                   replay.append(tour);	      // on stocke dans replay, la totalité des tours de la partie
		   state.fin=1;		      // FIN DE LA PARTIE
                   file.open("replay.txt");  // ouverture du fichier texte replay
		   file << replay;           // ecriture de replay dans le fichier texte replay
                   file.close();             // fin ecriture du fichier texte
       		
				
		}
// en cours de partie
		else { 
			if(count < state.nb_hero*4+1){
                        	tour.append(command);
                        }
			else {  std::cout<<"*****New Turn ******"<<std::endl;
                          	count  = 0;
                          	replay.append(tour);
                         	tour.clear();
                          	tour.append(command);
                          
                        }
                } 
                     
		     	
	}
  }                 
		
    return 0;
}




