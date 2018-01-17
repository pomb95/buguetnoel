/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

#include "Engine.h"
#include "Command.h"
#include "MoveChar.h"
#include "Attack.h"
#include <iostream>
#include <vector>
#include "json/json.h"
#include <fstream>
#include <unistd.h>




engine::Engine::Engine() {
    /*engine::MoveChar command(0,0);
    this->addCommand(command);*/
    char_sel=0;
    mov_left=3;
    att_left=1;

}

engine::Engine::~Engine() {}

void engine::Engine::addCommand(Command cmd){
    commands.push_back(cmd);
    
}


//update sans les thread
void engine::Engine::Update(state::State& state_game, bool rollback) {
    //std::cout << "Il reste  : " << commands.size() <<" commandes "<< std::endl;
    if (not(rollback)){
        state_game.list_element[char_sel].setSelected(1);
        while(!commands.empty()){
            commands[0].execute(state_game);
            save_commands.push_back(commands[0]);
            if(commands[0].getId()==1)
                mov_left=mov_left-1;
            if(commands[0].getId()==2)
                att_left=att_left-1;
	//std::cout<<mov_left<<std::endl;
            commands.erase(commands.begin());
        }
        state_game.enable_state=1;


            if(mov_left==0)
                if(att_left==0)
            {
            state_game.list_element[char_sel].setSelected(0);

            char_sel=(char_sel+1)%6;

            while(state_game.list_element[char_sel].getLife()<=0){

                char_sel=(char_sel+1)%6;
            }

            mov_left=state_game.list_element[char_sel].getMovement();
            att_left=1;
            state_game.list_element[char_sel].setSelected(1);

            }
        //std::cout<<state_game.list_element[char_sel].getName()<<std::endl;
    //std::cout << "Engine :::On a notifié à l'état que une commande a été executé "<< std::endl;
    }
    if (rollback){



            if(mov_left==3)
                if(att_left==1)
            {
            state_game.list_element[char_sel].setSelected(0);

            char_sel=(char_sel-1)%6;


            mov_left=0;
            att_left=0;
            state_game.list_element[char_sel].setSelected(1);

            }
state_game.list_element[char_sel].setSelected(1);
        //while(!save_commands.empty()){
            save_commands[save_commands.size()-1].undo(state_game);
            if(save_commands[save_commands.size()-1].getId()==1)
                mov_left=mov_left+1;
            if(save_commands[save_commands.size()-1].getId()==2)
                att_left=att_left+1;

            save_commands.pop_back();
        //}
        state_game.enable_state=1;

    }
}

void engine::Engine::UpdateTh(state::State& state_game){//update avec thread
    //std::cout << "Lancement du thread engine" << std::endl;
    int message = 0;
    int nb_command = 1;
    while(state_game.fin != 1){
	
        if (!message){
          //  std::cout << "En attente de commande" << std::endl;
            message = 1;
        }
        if (fin_tour){
			std::string comm="curl --silent -X GET http://localhost:5050/command/"+std::to_string(nb_command);
			    char buffer[128];
				std::string result = "";
				FILE* pipe = popen(comm.c_str(), "r");
				if (!pipe) throw std::runtime_error("popen() failed!");
				try {
				while (!feof(pipe)) {
				if (fgets(buffer, 128, pipe) != NULL)
					result += buffer;
					}
					} catch (...) {
			pclose(pipe);
					throw;
				}
				pclose(pipe);
				
							Json::Value root; 
							Json::Reader reader;
							reader.parse( result.c_str(), root );
							if((root["Id"]==1)||(root["Id"]==2)){
							engine::Command commandadv;
							commandadv.deserialize(	root);
							
							this->addCommand(commandadv);
							nb_command++;
							}
            message = 0;
            state_game.list_element[char_sel].setSelected(1);
            {
           // std::lock_guard<std::mutex> lock(mutex);
            while(!commands.empty()){
                commands[0].execute(state_game);
                save_commands.push_back(commands[0]);
                if(commands[0].getId()==1)
                    mov_left=mov_left-1;
                if(commands[0].getId()==2)
                    att_left=att_left-1;
    	          //  std::cout<<mov_left<<std::endl;
                    commands.erase(commands.begin());
                //std::cout << "execution des commandes dans le thread" << std::endl;
            }
        }
            state_game.enable_state=1;

                if(mov_left==0){
                    if(att_left==0){
                        state_game.list_element[char_sel].setSelected(0);

                        char_sel=(char_sel+1)%6;

                        while(state_game.list_element[char_sel].getLife()<=0){

                            char_sel=(char_sel+1)%6;
                        }

                        mov_left=state_game.list_element[char_sel].getMovement();
                        att_left=1;
                        state_game.list_element[char_sel].setSelected(1);
                    }
                }

        }
        if(fin_tour) fin_tour = false;
        if(!engine_update)  engine_update = true;
    }
}



void engine::Engine::testInit(){
}
