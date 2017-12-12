/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

#include <iostream>
#include "RandomAi.h"
#include "Ai.h"
#include <cstdlib>
#include <iostream>
#include <engine/MoveChar.h>
#include <engine/Attack.h>
#include <sys/time.h>

ai::RandomAi::RandomAi() {
    Id=1;
}
ai::RandomAi::~RandomAi() {}
ai::RandomAi::RandomAi(int team) {
    Id=1;
    Team=team;
}

engine::Command ai::RandomAi::play(engine::Engine& engine,int character,state::State& state){


         struct timeval time;
         gettimeofday(&time,NULL);
         std::srand((time.tv_sec * 1000) + (time.tv_usec / 1000));


        //engine::CheckAround command0(character);
        //engine.addCommand(command0);
        if(state.list_element[character].getTeam()==Team){
                if(engine.mov_left!=0){

                     int random=std::rand();
                     engine::Command command=list_mov[random%list_mov.size()];
                     command.setCharacter(character);
                    engine.addCommand(command);}else
                    {
                     if(engine.att_left!=0){

                         int random=std::rand();
                      engine::Command command=list_att[(random+1)%list_att.size()];
                      command.setAttaquant(character);
                    engine.addCommand(command);
                     }
                    }
                }//else{
            //std::cout<<"Ce n'est pas le tour de l'IA "<<Team<<std::endl;
               // }
	engine::Command com;
return com;


}


























