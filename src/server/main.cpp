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
	State state;
	Engine engine;
	state.init();
	ai::HeuristicAi bot1(0);
	ai::HeuristicAi bot2(1);
	bot1.init();
	bot2.init();
	state.Update();
	Json::Value serial;
	Command record;
	ofstream file;
	file.open("replay.txt"); 
	while (state.fin !=1){
							if (state.list_element[engine.char_sel].getTeam()==0){
                        	record = bot1.play(engine,engine.char_sel,state);
                        	}
                        	else{
                        	record = bot2.play(engine,engine.char_sel,state);
                        	
                        	}
                        	serial["command"]["Id"]=record.getId();
							serial["command"]["character"]=record.getCharacter();
							serial["command"]["direction"]=record.getDirection();
							serial["command"]["attaquant"]=record.getAttaquant();
							serial["command"]["victime"]=record.getVictime();
							
							
							
							file << serial;           
						
							
                        	engine.Update(state);
                        	
                       	 	state.Update();
			  	usleep(50000);
		      

               	      if(state.fin==1){
			state.fin=1;
               		 std::cout <<"Fin de Partie"<<std::endl;
				file.close();
		     } 
                 }
}

    return 0;
}






