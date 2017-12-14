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
	ofstream file;
	Json::Value replay;
	Json::Value command;
        Json::Value tour;
	Command record;
        int count = 0;
        
        //On recupere les positions des joueurs
        Tiles tile;
        tile.convert(state);
        for (unsigned i = 0; i<state.nb_hero; i++) {
             if((state.list_element[i].getTypeId()==7)||(state.list_element[i].getTypeId()==6)||(state.list_element[i].getTypeId()==8)||(state.list_element[i].getTypeId()==9)||(state.list_element[i].getTypeId()==10)){
                
                state.list_element[i].setPosX(static_cast<int> (tile.list_pos_hero[i].x));
                state.list_element[i].setPosY(static_cast<int> (tile.list_pos_hero[i].y));
             
             }}
        
        std::cout<<"*****New Play ******"<<std::endl;
	std::cout<<"*****New Turn ******"<<std::endl;

	while(state.fin !=1){
            
			if (state.list_element[engine.char_sel].getTeam()==0){
                            record = bot1.play(engine,engine.char_sel,state);
                        }
                        else{
                            record = bot2.play(engine,engine.char_sel,state);
                        	
                        }
                       
                       
                        engine.Update(state);	
                       	state.Update();
			usleep(50000);
                        command = record.serialize();
                        count = count +1;
                        
		     
                          
                          

               	      if(state.fin==1){
                           tour.append(command);
                          replay.append(tour);
			state.fin=1;
                        file.open("replay.txt"); 
		
                     file << replay;
                     file.close();
               		
				
		     }else {
                           if(count < state.nb_hero*4+1){
                        
			tour.append(command);
                      }else {
                          std::cout<<"*****New Turn ******"<<std::endl;
                          count  = 0;
                          replay.append(tour);
                          tour.clear();
                          tour.append(command);
                          
                      }
                     } 
                     
		     	
                 }
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
	ifstream file;
        Json::Value replay;
	Json::Value command;
	Command com;
        int count = 0;
        file.open("replay.txt"); 
		
        file >> replay;
        file.close();
        std::cout<<"*****New Play ******"<<std::endl;
	

	
            //On recupere les positions des joueurs
        Tiles tile;
        tile.convert(state);
        for (unsigned i = 0; i<state.nb_hero; i++) {
             if((state.list_element[i].getTypeId()==7)||(state.list_element[i].getTypeId()==6)||(state.list_element[i].getTypeId()==8)||(state.list_element[i].getTypeId()==9)||(state.list_element[i].getTypeId()==10)){
                
                state.list_element[i].setPosX(static_cast<int> (tile.list_pos_hero[i].x));
                state.list_element[i].setPosY(static_cast<int> (tile.list_pos_hero[i].y));
             
             }}
                       
            for(int i = 0 ;i<replay.size();i++ ){
                 std::cout<<"*****New Turn ******"<<std::endl;
                for (int j = 0;j<replay[i].size();j++){
                    Json::Value command;
                    command=replay[i][j];
                    com.deserialize(command);
                    engine.addCommand(com);
                     engine.Update(state);	
                       	state.Update();
			usleep(50000);
		   
               		
                        
				
		     } 
                       
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



