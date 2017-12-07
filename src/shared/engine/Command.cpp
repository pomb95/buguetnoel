/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

#include "Command.h"
#include "ai.h"
#include "CheckAround.h"
#include <iostream>
#include <math.h>



int droite;
engine::Command::Command() {}
engine::Command::~Command() {}
void engine::Command::execute (state::State& state){
    //Commande de déplacement
    if(Id==1){
            		//std::cout << "position actuelle : " << state.list_element[character].getPosX() << ", " <<state.list_element[character].getPosY() << std::endl;
            //std::cout << "position actuelle : " << state.list_element[1].getPosX() << ", " <<state.list_element[1].getPosY() << std::endl;
            //std::cout << "position actuelle : " << state.list_element[2].getPosX() << ", " state.list_element[2].getPosY() << std::endl;
            //std::cout << "position actuelle : " << state.list_element[3].getPosX() << ", " <<state.list_element[3].getPosY() << std::endl;
            //std::cout << "position actuelle : " << state.list_element[4].getPosX() << ", " <<state.list_element[4].getPosY() << std::endl;
            //std::cout << "position actuelle : " << state.list_element[5].getPosX() << ", " <<state.list_element[5].getPosY() << std::endl;
            //std::cout << "position actuelle : " << state.list_element[6].getPosX() << ", " <<state.list_element[6].getPosY() << std::endl;
            //std::cout << "position actuelle : " << state.list_element[7].getPosX() << ", " <<state.list_element[7].getPosY() << std::endl;
            //std::cout << "position actuelle : " << state.list_element[8].getPosX() << ", " <<state.list_element[8].getPosY() << std::endl;
            //std::cout << "position actuelle : " << state.list_element[9].getPosX() << ", " <<state.list_element[9].getPosY() << std::endl;
           // std::cout << "************************************************* " << std::endl;
            //std::cout << "nombre d'element " << state.list_element[7].getName() << std::endl;


        	if(direction==5){
                              }

                else if(direction==6){
				if  ( state.list_element[character].getPosX()>=672-40){
				      std::cout << "déplacement pas possible"<<std::endl;}

				else{
				      state.list_element[character].setPosX(state.list_element[character].getPosX() + 28);}

                              }

                else if(direction==8){
				if  ( state.list_element[character].getPosY()<=0){
				      std::cout << "déplacement pas possible"<<std::endl;}

				else{
				      state.list_element[character].setPosY(state.list_element[character].getPosY() - 28);}

                              }

                else if(direction==2){

				if  ( state.list_element[character].getPosY()>=672-40){
				      std::cout << "déplacement pas possible"<<std::endl;}

				else{
                   		      state.list_element[character].setPosY(state.list_element[character].getPosY() + 28);}

                              }

                else if(direction==4){
				if  ( state.list_element[character].getPosX()<=0){
				      std::cout << "déplacement pas possible"<<std::endl;}

				else{
                   		      state.list_element[character].setPosX(state.list_element[character].getPosX() - 28);
                                 state.list_element[character].setDirection(0);}

        }else{
            std::cout<<"cette direction n'existe pas :)"<<std::endl;
        }

        //std::cout << "new position : " << state.list_element[character].getPosX() << ", " << state.list_element[character].getPosY() << std::endl;


    }
        //attaque
	if(Id==2){


            if((state.list_element[victime].getPosX()>state.list_element[attaquant].getPosX()-state.list_element[attaquant].getRange()*28)&&
                (state.list_element[victime].getPosX()<state.list_element[attaquant].getPosX()+(state.list_element[attaquant].getRange()+1)*28)&&
                    (state.list_element[victime].getPosY()<state.list_element[attaquant].getPosY()+(state.list_element[attaquant].getRange()+1)*28)&&
                    (state.list_element[victime].getPosY()>state.list_element[attaquant].getPosY()-state.list_element[attaquant].getRange()*28)){

                if(state.list_element[victime].getAlive()==1){
                if(state.list_element[victime].getTeam()!=state.list_element[attaquant].getTeam()){
                    state.list_element[victime].setLife(state.list_element[victime].getLife()-state.list_element[attaquant].getATK());
                    if (state.list_element[victime].getLife() < 0){
                        state.list_element[victime].setLife(0);
                    }
                    std::cout << state.list_element[attaquant].getName()<< " de l'equipe "<< state.list_element[attaquant].getTeam()<< " a attaqué " <<  state.list_element[victime].getName() <<" de l'equipe "<< state.list_element[victime].getTeam()<< ". Il lui reste " << state.list_element[victime].getLife() << " point de vie." <<std::endl;
                }else
                {std::cout<<"Adversaire est trop loin"<<std::endl;}
            }
            else
            {
                std::cout << state.list_element[victime].getName()<< " est déjà mort" <<std::endl;
            }
	   }
	    else{std::cout<<state.list_element[victime].getName()<<" est hors porté"<<std::endl;}
    }

}

void engine::Command::undo (state::State& state){
if(Id==1){
                //std::cout << "position actuelle : " << state.list_element[character].getPosX() << ", " <<state.list_element[character].getPosY() << std::endl;
        //std::cout << "position actuelle : " << state.list_element[1].getPosX() << ", " <<state.list_element[1].getPosY() << std::endl;
        //std::cout << "position actuelle : " << state.list_element[2].getPosX() << ", " state.list_element[2].getPosY() << std::endl;
        //std::cout << "position actuelle : " << state.list_element[3].getPosX() << ", " <<state.list_element[3].getPosY() << std::endl;
        //std::cout << "position actuelle : " << state.list_element[4].getPosX() << ", " <<state.list_element[4].getPosY() << std::endl;
        //std::cout << "position actuelle : " << state.list_element[5].getPosX() << ", " <<state.list_element[5].getPosY() << std::endl;
        //std::cout << "position actuelle : " << state.list_element[6].getPosX() << ", " <<state.list_element[6].getPosY() << std::endl;
        //std::cout << "position actuelle : " << state.list_element[7].getPosX() << ", " <<state.list_element[7].getPosY() << std::endl;
        //std::cout << "position actuelle : " << state.list_element[8].getPosX() << ", " <<state.list_element[8].getPosY() << std::endl;
        //std::cout << "position actuelle : " << state.list_element[9].getPosX() << ", " <<state.list_element[9].getPosY() << std::endl;
       // std::cout << "************************************************* " << std::endl;
        //std::cout << "nombre d'element " << state.list_element[7].getName() << std::endl;


        if(direction==5){
                          }

            else if(direction==6){
            if  ( state.list_element[character].getPosX()>=672-40){
                  std::cout << "déplacement pas possible"<<std::endl;}

            else{
                  state.list_element[character].setPosX(state.list_element[character].getPosX() - 28);}

                          }

            else if(direction==8){
            if  ( state.list_element[character].getPosY()<=0){
                  std::cout << "déplacement pas possible"<<std::endl;}

            else{
                  state.list_element[character].setPosY(state.list_element[character].getPosY() + 28);}

                          }

            else if(direction==2){

            if  ( state.list_element[character].getPosY()>=672-40){
                  std::cout << "déplacement pas possible"<<std::endl;}

            else{
                          state.list_element[character].setPosY(state.list_element[character].getPosY() - 28);}

                          }

            else if(direction==4){
            if  ( state.list_element[character].getPosX()<=0){
                  std::cout << "déplacement pas possible"<<std::endl;}

            else{
                          state.list_element[character].setPosX(state.list_element[character].getPosX() + 28);
                             state.list_element[character].setDirection(0);}

    }else{
        std::cout<<"cette direction n'existe pas :)"<<std::endl;
    }

    //std::cout << "new position : " << state.list_element[character].getPosX() << ", " << state.list_element[character].getPosY() << std::endl;


}
    //attaque
if(Id==2){


        if((state.list_element[victime].getPosX()>state.list_element[attaquant].getPosX()-state.list_element[attaquant].getRange()*28)&&
            (state.list_element[victime].getPosX()<state.list_element[attaquant].getPosX()+(state.list_element[attaquant].getRange()+1)*28)&&
                (state.list_element[victime].getPosY()<state.list_element[attaquant].getPosY()+(state.list_element[attaquant].getRange()+1)*28)&&
                (state.list_element[victime].getPosY()>state.list_element[attaquant].getPosY()-state.list_element[attaquant].getRange()*28)){

           
            if(state.list_element[victime].getTeam()!=state.list_element[attaquant].getTeam()){
                state.list_element[victime].setLife(state.list_element[victime].getLife()+state.list_element[attaquant].getATK());
                if (state.list_element[victime].getLife() < 0){
                    state.list_element[victime].setLife(0);
                }
                std::cout << state.list_element[victime].getName() <<" de l'equipe "<< state.list_element[victime].getTeam()<< " a retrouvé  " << state.list_element[attaquant].getATK() << " point de vie." <<std::endl;
            }else
            {std::cout<<"Aucun dégat n'a été infligé"<<std::endl;}
        
   }
    else{std::cout<<"Aucun dégat n'a été infligé"<<std::endl;}
}

}

int engine::Command::getAttaquant() const {
    return attaquant;
}

int engine::Command::getCharacter() const {
    return character;
}

int engine::Command::getDirection() const {
    return direction;
}

int engine::Command::getId() const {
    return Id;
}

int engine::Command::getVictime() const {
    return victime;
}

void engine::Command::setAttaquant(int attaquant) {
    this->attaquant =  attaquant;
}

void engine::Command::setCharacter(int character) {
    this->character = character;
}


void engine::Command::setDirection(int direction) {
    this->direction = direction;
}

void engine::Command::setId(int Id) {
    this->Id = Id;
}

void engine::Command::setVictime(int victime) {
    this->victime = victime;
}
