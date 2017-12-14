#include "Command.h"
#include "ai.h"
#include <iostream>
#include <math.h>
#include "Attack.h"
#include "MoveChar.h"



int droite;
engine::Command::Command() {
    Id=-1;
    character=-1;
    direction = -1;
    attaquant = -1;
    victime = -1;

}
engine::Command::~Command() {}
int engine::Command::execute (state::State& state){
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


        	    if(direction==5){return -1;
                                }

                else if(direction==6){
				        if  ( state.list_element[character].getPosX()>=672-40){
							  // std::cout << "déplacement pas possible vers droite"<<std::endl;
                              return -1;
                        }

				        else { state.list_element[character].setPosX(state.list_element[character].getPosX() + 28);
							   //std::cout << "droite"<<std::endl;

                        }
                }

                else if(direction==8){
						if  ( state.list_element[character].getPosY()<=0){
				             //std::cout << "déplacement pas possible vers haut"<<std::endl;
							 return -1;
					    }

				        else{ state.list_element[character].setPosY(state.list_element[character].getPosY() - 28);
							 // std::cout << "haut"<<std::endl;

                        }
                }

                else if(direction==2){
						if  ( state.list_element[character].getPosY()>=672-40){
							  // std::cout << "déplacement pas possible vers bas"<<std::endl;
							  return -1;
					    }

				        else{ state.list_element[character].setPosY(state.list_element[character].getPosY() + 28);
							 // std::cout << "bas"<<std::endl;

                        }
                }

                else if(direction==4){
						if  ( state.list_element[character].getPosX()<=0){
							  // std::cout << "déplacement pas possible vers gauche"<<std::endl;
							  return -1;
					    }

						else{ state.list_element[character].setPosX(state.list_element[character].getPosX() - 28);
							 //  std::cout << "gauche"<<std::endl;
                               //state.list_element[character].setDirection(0);
                        }

				}
				
				else{
						//std::cout<<"cette direction n'existe pas :)"<<std::endl;
						return -1;
				}

	//std::cout << "new position : " << state.list_element[character].getPosX() << ", " << state.list_element[character].getPosY() << std::endl;
	/*Json::Value jsonCommandes;
	Json::Value cmd;
	MoveChar.serialize(cmd);
	jsonCommandes.append(cmd);
	*/}


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
									//std::cout << state.list_element[attaquant].getName()<< " de l'equipe "<< state.list_element[attaquant].getTeam()<< " a attaqué " <<  state.list_element[victime].getName() <<" de l'equipe "<< state.list_element[victime].getTeam()<< ". Il lui reste " << state.list_element[victime].getLife() << " point de vie." <<std::endl;
							}
							else{ //std::cout<<"Adversaire est trop loin"<<std::endl;
								return -1;
							}
						}
						else{// std::cout << state.list_element[victime].getName()<< " est déjà mort" <<std::endl;
							return -1;
						}
				 }
				 else{ //std::cout<<state.list_element[victime].getName()<<" est hors porté"<<std::endl;
					 return -1;
				 }
				/* Json::Value jsonCommandes;
				 Json::Value cmd;
				 Attack.serialize(cmd);
				 jsonCommandes.append(cmd);
		    */}
			return 0;
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
            
                  state.list_element[character].setPosX(state.list_element[character].getPosX() - 28);}

                          

            else if(direction==8){
            
                  state.list_element[character].setPosY(state.list_element[character].getPosY() + 28);}

                          

            else if(direction==2){

           
                          state.list_element[character].setPosY(state.list_element[character].getPosY() - 28);}

                          

            else if(direction==4){
                     state.list_element[character].setPosX(state.list_element[character].getPosX() + 28);
                             state.list_element[character].setDirection(0);}

    else{
       // std::cout<<"cette direction n'existe pas :)"<<std::endl;
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
                state.list_element[victime].setLife(state.list_element[victime].getLife()-state.list_element[attaquant].getATK());
                if (state.list_element[victime].getLife() < 0){
                    state.list_element[victime].setLife(0);
                }
                //std::cout << state.list_element[victime].getName() <<" de l'equipe "<< state.list_element[victime].getTeam()<< " a retrouvé  " << state.list_element[attaquant].getATK() << " point de vie." <<std::endl;
            }else
            {//std::cout<<"Aucun dégat n'a été infligé"<<std::endl;
}
        
   }
    else{//std::cout<<"Aucun dégat n'a été infligé"<<std::endl;
}
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

Json::Value engine::Command::serialize(){
	Json::Value out;
        out["Id"]=this->getId();	
	out["character"]=this->getCharacter();
        out["direction"]=this->getDirection();
	out["attaquant"]=this->getAttaquant();
	out["victime"]=this->getVictime();
        
        return out;

}

void engine::Command::deserialize(Json::Value in){
        
        this->setId(in["Id"].asInt());	
	this->setCharacter(in["character"].asInt());
        this->setDirection(in["direction"].asInt());
	this->setAttaquant(in["attaquant"].asInt());
	this->setVictime(in["victime"].asInt());
        
        

}
