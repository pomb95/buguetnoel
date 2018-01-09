/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */
#include <iostream>
#include "state.h"

using namespace std;

namespace state{

    State::State(){
        path="res/level3.png";
        enable_render=0;
        enable_state=0;
        nb_hero=0;
        nb_tower=0;
        nb_center=0;
    }

    State::~State(){

    }

    void State::init(){


        Eniripsa hero1(0);
        this->addElement(hero1);

        Eniripsa hero2(1);
        this->addElement(hero2);

        Enutrof hero3(0);
        this->addElement(hero3);

        Sram hero4(1);
        this->addElement(hero4);

        Eniripsa hero5(0);
        this->addElement(hero5);

        Enutrof hero6(1);
        this->addElement(hero6);

        CommandTower tour1(0);
        this->addElement(tour1);

        CommandTower tour2(1);
        this->addElement(tour2);

        CommandCenter center1(0);
        this->addElement(center1);

        CommandCenter center2(1);
        this->addElement(center2);

        Coeur coeur_heros;



        for (int i = 0; i<nb_hero*list_element[1].getLife(); i++) {
            this->addElement(coeur_heros);

        }

        Selecteur sel;
        this->addElement(sel);

    }

    std::vector<Element> State::getListElement() {
        return list_element;
    }

    void state::State::Update(){
        int team0=0;
        int team1=0;
        if(enable_state==1){
        for (int i = 0; i<nb_hero; i++) {
            if(list_element[i].getAlive()==1){
                if(list_element[i].getLife()==0){
                    list_element[i].setAlive(0);
                 std::cout << list_element[i].getName() << " est mort." <<std::endl;
                }
            }
            if(list_element[i].getAlive()==0){
                if(list_element[i].getLife()>0){
                    list_element[i].setAlive(1);
                 std::cout << list_element[i].getName() << " est réanimé." <<std::endl;
                }
            }
        }

        for (unsigned i = nb_hero+nb_tower+nb_center; i<list_element.size(); i++) {

            if(list_element[i].getAlive()==1){
                if(list_element[static_cast<int>(i/10)-1].getLife()<=static_cast<int>(i%10)){
                    list_element[i].setAlive(0);
                // std::cout << list_element[static_cast<int>(i/10)].getName() << " a un coeur en moins ***." <<std::endl;
                }
            }
            else {if(list_element[static_cast<int>(i/10)-1].getLife()>static_cast<int>(i%10)){
                    list_element[i].setAlive(1);
                // std::cout << list_element[static_cast<int>(i/10)].getName() << " a un coeur en moins ***." <<std::endl;
                }

            }
        }
        for (int h=0;h<6;h++){
            if(list_element[h].getAlive()==1){
                if(list_element[h].getTeam()==1)
                {team1=team1+1;}
                else{
                    team0=team0+1;}}}

            if(team0==0){
                std::cout<<"-------------------------------------"<<std::endl;
                std::cout<<"-------------------------------------"<<std::endl;
                std::cout<<"**********TEAM 1 A GAGNE*************"<<std::endl;
                std::cout<<"-------------------------------------"<<std::endl;
                std::cout<<"-------------------------------------"<<std::endl;


                fin=1;
            }
                if(team1==0){
                std::cout<<"-------------------------------------"<<std::endl;
                std::cout<<"-------------------------------------"<<std::endl;
                std::cout<<"**********TEAM 0 A GAGNE*************"<<std::endl;
                std::cout<<"-------------------------------------"<<std::endl;
                std::cout<<"-------------------------------------"<<std::endl;



                fin=1;
            }


        enable_state=0;
        enable_render=1;
         //std::cout <<" State ::: On a notifié au rendu que l'état a changé et au moteur que les modifications ont été effectué "<<std::endl;
        }
    }
    void state::State::addElement(state::Element element){

    if((element.getTypeId()==7)||(element.getTypeId()==6)||
                    (element.getTypeId()==8)||(element.getTypeId()==9)||(element.getTypeId()==10)){

        nb_hero++;
        list_element.push_back(element);

        }
    else if(element.getTypeId()==4){
        nb_center++;
        list_element.push_back(element);
    }
    else if(element.getTypeId()==3){
        nb_tower++;
        list_element.push_back(element);
    }

    else
        {
         list_element.push_back(element);
        }

    }

}

state::State state::State::clone (){
    state::State st;
    for (unsigned int i = 0; i < this->list_element.size(); i++){
        st.addElement(this->list_element[i]);
    }
    return st;
}


void state::State::addState (state::State state){
    list_state.push_back(state);
}
