#include <iostream>
#include <SFML/Graphics.hpp>
#include "state.h"
#include "render.h"
#include "engine.h"
#include "ai.h"
#include <unistd.h>
#include "json/json.h"
#include <iostream>
#include <fstream>

using namespace std;
using namespace state;
using namespace render;
using namespace engine;

int main (int argc, char* argv[]){
 if ((argv[1] != NULL) && string(argv[1]) == "record") {
	std::cout<<"Appuyer sur B pour effectuer une action "<<std::endl;
	State state;
	Engine engine;
	state.init();
	ai::HeuristicAi bot1(0);
	ai::HeuristicAi bot2(1);
	bot1.init();
	bot2.init();
	state.Update();
	while (state.fin !=1){
                        	bot1.play(engine,engine.char_sel,state);
                        	bot2.play(engine,engine.char_sel,state);
                        	engine.Update(state);
                       	 	state.Update();
			  	usleep(50000);
		      

               	      if(state.fin==1){
			state.fin=1;
               		 std::cout <<"Fin de Partie"<<std::endl;
			std::ofstream file_id;
			file_id.open("replay.txt");  // creation du fichier txt replay
			file_id.close();
		     } 
                 }
}

    return 0;
}
