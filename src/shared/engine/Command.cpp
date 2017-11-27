/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

#include "Command.h"
#include "CheckAround.h"
#include <iostream>
#include <math.h>



int droite;
engine::Command::Command() {}
engine::Command::~Command() {}
void engine::Command::execute (state::State& state){
    //Commande de déplacement
    if(Id==1){
            //		std::cout << "position actuelle : " << state.list_element[0].getPosX() << ", " <<state.list_element[0].getPosY() << std::endl;
            std::cout << "position actuelle : " << state.list_element[1].getPosX() << ", " <<state.list_element[1].getPosY() << std::endl;
            //std::cout << "position actuelle : " << state.list_element[2].getPosX() << ", " state.list_element[2].getPosY() << std::endl;
            //std::cout << "position actuelle : " << state.list_element[3].getPosX() << ", " <<state.list_element[3].getPosY() << std::endl;
            //std::cout << "position actuelle : " << state.list_element[4].getPosX() << ", " <<state.list_element[4].getPosY() << std::endl;
            //std::cout << "position actuelle : " << state.list_element[5].getPosX() << ", " <<state.list_element[5].getPosY() << std::endl;
            std::cout << "position actuelle : " << state.list_element[6].getPosX() << ", " <<state.list_element[6].getPosY() << std::endl;
            //std::cout << "position actuelle : " << state.list_element[7].getPosX() << ", " <<state.list_element[7].getPosY() << std::endl;
            //std::cout << "position actuelle : " << state.list_element[8].getPosX() << ", " <<state.list_element[8].getPosY() << std::endl;
            //std::cout << "position actuelle : " << state.list_element[9].getPosX() << ", " <<state.list_element[9].getPosY() << std::endl;
            std::cout << "************************************************* " << std::endl;
            std::cout << "nombre d'element " << state.list_element[7].getName() << std::endl;


        	if(direction==6){ //std::cout << state.list_element[character].getName() << " veut se déplacer vers la droite" << std::endl;
			  	 for (int i=0;i<10;i++){
					if  ( state.list_element[character].getPosX()+28 ==state.list_element[i].getPosX()){
						droite = 1;
						std::cout << "déplacement pas possible"<<std::endl;
						state.list_element[character].setPosX(state.list_element[character].getPosX());
					}
					else {droite = 0;
					std::cout << "déplacement possible"<<std::endl;}
				}
				if ((droite ==0) & (state.list_element[character].getPosX() >= 672)){
					std::cout<<"pas possible"<<std::endl;}
                else {//std::cout << state.list_element[character].getName() << " se déplace : droite" << std::endl;
				       state.list_element[character].setPosX(state.list_element[character].getPosX() + 28);
                                 state.list_element[character].setDirection(1);
                                 }

                                 }

                else if(direction==8){// std::cout << state.list_element[character].getName() << " veut se déplacer vers le haut" << std::endl;
				if  ( state.list_element[character].getPosY()<=0){
				      std::cout << "déplacement pas possible"<<std::endl;}

				else{ //std::cout << state.list_element[character].getName() << " se déplace : haut" << std::endl;
				      state.list_element[character].setPosY(state.list_element[character].getPosY() - 28);}

                              }

                else if(direction==2){ //std::cout << state.list_element[character].getName() << " veut se déplacer en bas" << std::endl;
				if  ( state.list_element[character].getPosY()>=672){
				      std::cout << "déplacement pas possible"<<std::endl;}

				else{ //std::cout << state.list_element[character].getName() << " se déplace : bas" << std::endl;
                   		      state.list_element[character].setPosY(state.list_element[character].getPosY() + 28);}

                              }

                else if(direction==4){ //std::cout << state.list_element[character].getName() << " veut se déplacer à gauche" << std::endl;
				if  ( state.list_element[character].getPosX()<=0){
				      std::cout << "déplacement pas possible"<<std::endl;}

				else{ //std::cout << state.list_element[character].getName() << " se déplace : gauche" << std::endl;
                   		      state.list_element[character].setPosX(state.list_element[character].getPosX() - 28);
                                 state.list_element[character].setDirection(0);}

        }else{
            std::cout<<"cette direction n'existe pas :)"<<std::endl;
        }

        std::cout << "new position : " << state.list_element[character].getPosX() << ", " << state.list_element[character].getPosY() << std::endl;


    }
        //attaque
	if(Id==2){


            if((state.list_element[victime].getPosX()>state.list_element[attaquant].getPosX()-state.list_element[attaquant].getRange()*28)&&
                (state.list_element[victime].getPosX()<state.list_element[attaquant].getPosX()+(state.list_element[attaquant].getRange()+1)*28)&&
                    (state.list_element[victime].getPosY()<state.list_element[attaquant].getPosY()+(state.list_element[attaquant].getRange()+1)*28)&&
                    (state.list_element[victime].getPosY()>state.list_element[attaquant].getPosY()-state.list_element[attaquant].getRange()*28)){

                if(state.list_element[victime].getAlive()==1){
                if(state.list_element[victime].getTeam()!=state.list_element[attaquant].getTeam()){
                    state.list_element[victime].setLife(state.list_element[victime].getLife()-degat);
                    std::cout << state.list_element[attaquant].getName()<< " de l'equipe "<< state.list_element[attaquant].getTeam()<< " a attaqué " <<  state.list_element[victime].getName() <<" de l'equipe "<< state.list_element[victime].getTeam()<< ". Il lui reste " << state.list_element[victime].getLife() << " point de vie." <<std::endl;
                }else
                {std::cout<<"Impossible d'attaquer un personnages de la même équipe"<<std::endl;}
            }
            else
            {
                std::cout << state.list_element[victime].getName()<< " est déjà mort" <<std::endl;
            }
	   }
	    else{std::cout<<state.list_element[victime].getName()<<" est hors porté"<<std::endl;}
        }
        //Detection des éléments
        if(Id == 3){
            std::cout << "position " << state.list_element[character].getName() <<" : "<< state.list_element[character].getPosX() << ", " << state.list_element[character].getPosY() << std::endl;
            std::cout << "Detection des éléments..." << std::endl;
            int e = 0;
            int increment = 1;
            int y2 = 0;
            int posX = state.list_element[character].getPosX();
            //std::cout << "posX = " << posX << std::endl;
            int posY = state.list_element[character].getPosY();
            //std::cout << "posY = " << posY << std::endl;
            int r = 10 ;//state.list_element[character].getRange();
            //std::cout << "range = " << r << std::endl;
            for (int x = posX-r*28; x <= posX + r*28; x += 28){
                //std::cout << "CheckX = " << x << std::endl;
                //std::cout << "increment = " << increment << std::endl;
                for (int y = posY-y2*28; y <= posY + y2*28; y+=28){
                    //std::cout << "CheckY = " << y << std::endl;
                    for (int z = 0; z < (int)state.getListElement().size(); z++){
                        //std::cout << "element actuel : " << state.list_element[z].getName() << std::endl;
                        if (x == state.list_element[z].getPosX() && y == state.list_element[z].getPosY()){
                            if (x != posX || y != posY){
                                std::cout << state.list_element[character].getName() << " voit un " << state.list_element[z].getName() << std::endl;
                                if ( y < posY && x < posX) {std::cout << "il est en haut à gauche" << std::endl;}
                                else if ( y < posY && x == posX) {std::cout << "il est en haut" << std::endl;}
                                else if ( y < posY && x > posX) {std::cout << "il est en haut à doite" << std::endl;}
                                else if ( y == posY && x > posX) {std::cout << "il est à droite" << std::endl;}
                                else if ( y > posY && x > posX) {std::cout << "il est en bas à droite" << std::endl;}
                                else if ( y > posY && x == posX) {std::cout << "il est en bas" << std::endl;}
                                else if ( y > posY && x < posX) {std::cout << "il est en bas à gauche" << std::endl;}
                                else if ( y == posY && x < posX) {std::cout << "il est à gauche" << std::endl;}
                                std::cout << "Distance = " << sqrt(pow((x-posX),2)+pow((y-posY),2)) << std::endl;
                                listElementChecked.push_back(state.list_element[z]);
                                e = 1;
                            }

                        }
                    }

                }
                //std::cout << " " << std::endl;
                if (x == posX) increment = -1;
                y2 += increment;

            }
            if (e == 0) std::cout << state.list_element[character].getName() << " ne voit rien" << std::endl;
        }
}

int engine::Command::getAttaquant() const {
    return attaquant;
}

int engine::Command::getCharacter() const {
    return character;
}

int engine::Command::getDegat() const {
    return degat;
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

void engine::Command::setDegat(int degat) {
    this->degat = degat;
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
