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
	ofstream file;
	Json::Value replay;
	Json::Value command;
	Json::Value jsonCommandes;
	Command record;
	file.open("replay.txt"); 

	while(state.fin !=1){
			if (state.list_element[engine.char_sel].getTeam()==0){
                            record = bot1.play(engine,engine.char_sel,state);
                        }
                        else{
                            record = bot2.play(engine,engine.char_sel,state);
                        	
                        }
            command["commande"]=record.getId();
	        command["character"]=record.getCharacter();
			command["direction"]=record.getDirection();
			command["attaquant"]=record.getAttaquant();
			command["victime"]=record.getVictime();
							
			
			replay.append(jsonCommandes);
						
		 	//file << serial;           
						
							
                        	engine.Update(state);
                        	
                       	 	state.Update();
			  	usleep(50000);
		      

               	      if(state.fin==1){
			state.fin=1;
               		 std::cout <<"Fin de Partie"<<std::endl;
				file.close();
		     } 
		     Json::StyledWriter styledWriter;
			file << styledWriter.write(replay);
		     	
                 }
		}
    return 0;
}

/*
	ofstream file;
	Json::Value jsonCommandes;
	Json::Value replay;
	file.open("replay.txt"); 

	while(state.fin!=1){
		//	if (state.list_element[engine.char_sel].getTeam()==0){
                            bot1.play(engine,engine.char_sel,state);
							bot2.play(engine,engine.char_sel,state);
                        	
                        
							
			Json::StyledWriter styledWriter;
			replay.append(jsonCommandes);
			file << styledWriter.write(replay);				
		 	//file << serial;           
						
					
                        	
                       	 	state.Update();
							usleep(50000);
		      

               	      if(state.fin==1){
			state.fin=1;
               		 std::cout <<"Fin de Partie"<<std::endl;
				file.close();
		     } 
                 }
    return 0;
}
*/



