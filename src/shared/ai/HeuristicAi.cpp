/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

#include <iostream>
#include <vector>
#include "HeuristicAi.h"
#include "Ai.h"
#include <cstdlib>
#include <iostream>
#include <math.h>
#include "engine.h"
#include "ai.h"
#include <engine/MoveChar.h>
#include <engine/Attack.h>
#include <engine/CheckAround.h>
#include <sys/time.h>

float distance(int x1, int y1, int x2, int y2);

ai::HeuristicAi::HeuristicAi() {
    Id=2;
}
ai::HeuristicAi::~HeuristicAi() {}
ai::HeuristicAi::HeuristicAi(int team) {
    Id=2;
    Team=team;
}

/*void ai::HeuristicAi::check (state::State& state, int character){
    std::cout << "position " << state.list_element[character].getName() <<" : "<< state.list_element[character].getPosX() << ", " << state.list_element[character].getPosY() << std::endl;
    std::cout << "Detection des éléments..." << std::endl;
    clearListInt(score_att);
    clearListInt(score_mov);
    clearListInt(listElementChecked);

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
                        if ( y < posY && x < posX) {//en fct de la pos on augmente le score de chaque commande
                            //std::cout << "il est en haut à gauche" << std::endl;
                            score_mov[1] += 1;
                            score_mov[3] += 1;
                        }
                        else if ( y < posY && x == posX) {
                            //std::cout << "il est en haut" << std::endl;
                            score_mov[3] += 1;
                        }
                        else if ( y < posY && x > posX) {
                            //std::cout << "il est en haut à doite" << std::endl;
                            score_mov[3] += 1;
                            score_mov[2] += 1;
                        }
                        else if ( y == posY && x > posX) {
                            //std::cout << "il est à droite" << std::endl;
                            score_mov[2] += 1;
                        }
                        else if ( y > posY && x > posX) {
                            //std::cout << "il est en bas à droite" << std::endl;
                            score_mov[2] += 1;
                            score_mov[0] += 1;
                        }
                        else if ( y > posY && x == posX) {
                            //std::cout << "il est en bas" << std::endl;
                            score_mov[0] += 1;
                        }
                        else if ( y > posY && x < posX) {
                            //std::cout << "il est en bas à gauche" << std::endl;
                            score_mov[0] += 1;
                            score_mov[1] += 1;
                        }
                        else if ( y == posY && x < posX) {
                            //std::cout << "il est à gauche" << std::endl;
                            score_mov[1] += 1;
                        }
                        //std::cout << "Distance = " << distance(x,y,posX,posY) << std::endl;
                        listElementChecked.push_back(z);
                        std::cout << "move score : "<<std::endl;
                        for (unsigned int i = 0; i < score_mov.size(); i++){
                            std::cout << score_mov[i] <<std::endl;
                        }
                        e = 1;
                    }
                    else{
                      std::cout << "Aucun élément à proximité" << std::endl;
                    }

                }
            }

        }
        //std::cout << " " << std::endl;
        if (x == posX) increment = -1;
        y2 += increment;

    }
    if (e){
        std::cout << listElementChecked.size() << " éléments à portée " << std::endl;
        int indice_max = 0;
        int max = score_mov[0];
        for (unsigned int i = 0; i < score_mov.size(); i++){
            if (score_mov[i] > max){
                indice_max = i;
                max = score_mov[i];
            }
        }
        std::cout << "déplacement suivant la commande " << indice_max << std::endl;
        switch (indice_max){
            case 0:
                std::cout << "===> bas" << std::endl;
                break;
            case 1:
                std::cout << "==> gauche" << std::endl;
                break;
            case 2:
                std::cout << "==> droite" << std::endl;
                break;
            case 3:
                std::cout << "==> haut" << std::endl;
                break;
        }
    }
    else{
        std::cout << state.list_element[character].getName() << " ne voit rien" << std::endl;
    }
}*/


void ai::HeuristicAi::play(engine::Engine& engine,int character,state::State& state){
    //debut check
    /*std::cout << "position " << state.list_element[character].getName() <<" : "<< state.list_element[character].getPosX() << ", " << state.list_element[character].getPosY() << std::endl;
    std::cout << "Detection des éléments..." << std::endl;
    clearListInt(score_att);
    clearListInt(score_mov);
    clearListInt(listElementChecked);

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
                        if ( y < posY && x < posX) {//en fct de la pos on augmente le score de chaque commande
                            //std::cout << "il est en haut à gauche" << std::endl;
                            score_mov[1] += 1;
                            score_mov[3] += 1;
                        }
                        else if ( y < posY && x == posX) {
                            //std::cout << "il est en haut" << std::endl;
                            score_mov[3] += 1;
                        }
                        else if ( y < posY && x > posX) {
                            //std::cout << "il est en haut à doite" << std::endl;
                            score_mov[3] += 1;
                            score_mov[2] += 1;
                        }
                        else if ( y == posY && x > posX) {
                            //std::cout << "il est à droite" << std::endl;
                            score_mov[2] += 1;
                        }
                        else if ( y > posY && x > posX) {
                            //std::cout << "il est en bas à droite" << std::endl;
                            score_mov[2] += 1;
                            score_mov[0] += 1;
                        }
                        else if ( y > posY && x == posX) {
                            //std::cout << "il est en bas" << std::endl;
                            score_mov[0] += 1;
                        }
                        else if ( y > posY && x < posX) {
                            //std::cout << "il est en bas à gauche" << std::endl;
                            score_mov[0] += 1;
                            score_mov[1] += 1;
                        }
                        else if ( y == posY && x < posX) {
                            //std::cout << "il est à gauche" << std::endl;
                            score_mov[1] += 1;
                        }
                        //std::cout << "Distance = " << distance(x,y,posX,posY) << std::endl;
                        listElementChecked.push_back(z);
                        std::cout << "move score : "<<std::endl;
                        for (unsigned int i = 0; i < score_mov.size(); i++){
                            std::cout << score_mov[i] <<std::endl;
                        }
                        e = 1;
                    }
                    else{
                      std::cout << "Aucun élément à proximité" << std::endl;
                    }

                }
            }

        }
        //std::cout << " " << std::endl;
        if (x == posX) increment = -1;
        y2 += increment;

    }
    if (e){
        std::cout << listElementChecked.size() << " éléments à portée " << std::endl;
        int indice_max = 0;
        int max = score_mov[0];
        for (unsigned int i = 0; i < score_mov.size(); i++){
            if (score_mov[i] > max){
                indice_max = i;
                max = score_mov[i];
            }
        }
        std::cout << "déplacement suivant la commande " << indice_max << std::endl;
        switch (indice_max){
            case 0:
                std::cout << "===> bas" << std::endl;
                break;
            case 1:
                std::cout << "==> gauche" << std::endl;
                break;
            case 2:
                std::cout << "==> droite" << std::endl;
                break;
            case 3:
                std::cout << "==> haut" << std::endl;
                break;
        }
    }
    else{
        std::cout << state.list_element[character].getName() << " ne voit rien" << std::endl;
    }*/
//fin check
int id_max_mov = 0;
int id_max_att = 0;
int value = 0;
//engine::CheckAround command0(character);
//engine.addCommand(command0);
if(state.list_element[character].getTeam()==Team){

    if(engine.mov_left!=0){
        //debut check
        std::cout << "position " << state.list_element[character].getName() <<" : "<< state.list_element[character].getPosX() << ", " << state.list_element[character].getPosY() << std::endl;
        std::cout << "Detection des éléments..." << std::endl;
        clearListInt(score_att);
        clearListInt(score_mov);
        clearListInt(listElementChecked);

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
                            if ( y < posY && x < posX) {//en fct de la pos on augmente le score de chaque commande
                                //std::cout << "il est en haut à gauche" << std::endl;
                                score_mov[1] += 1;
                                score_mov[3] += 1;
                            }
                            else if ( y < posY && x == posX) {
                                //std::cout << "il est en haut" << std::endl;
                                score_mov[3] += 1;
                            }
                            else if ( y < posY && x > posX) {
                                //std::cout << "il est en haut à doite" << std::endl;
                                score_mov[3] += 1;
                                score_mov[2] += 1;
                            }
                            else if ( y == posY && x > posX) {
                                //std::cout << "il est à droite" << std::endl;
                                score_mov[2] += 1;
                            }
                            else if ( y > posY && x > posX) {
                                //std::cout << "il est en bas à droite" << std::endl;
                                score_mov[2] += 1;
                                score_mov[0] += 1;
                            }
                            else if ( y > posY && x == posX) {
                                //std::cout << "il est en bas" << std::endl;
                                score_mov[0] += 1;
                            }
                            else if ( y > posY && x < posX) {
                                //std::cout << "il est en bas à gauche" << std::endl;
                                score_mov[0] += 1;
                                score_mov[1] += 1;
                            }
                            else if ( y == posY && x < posX) {
                                //std::cout << "il est à gauche" << std::endl;
                                score_mov[1] += 1;
                            }
                            //std::cout << "Distance = " << distance(x,y,posX,posY) << std::endl;
                            listElementChecked.push_back(z);
                            std::cout << "move score : "<<std::endl;
                            for (unsigned int i = 0; i < score_mov.size(); i++){
                                std::cout << score_mov[i] <<std::endl;
                            }
                            e = 1;
                        }
                        else{
                          std::cout << "Aucun élément à proximité" << std::endl;
                        }

                    }
                }

            }
            //std::cout << " " << std::endl;
            if (x == posX) increment = -1;
            y2 += increment;

        }
        if (e){
            std::cout << listElementChecked.size() << " éléments à portée " << std::endl;
            int indice_max = 0;
            int max = score_mov[0];
            for (unsigned int i = 0; i < score_mov.size(); i++){
                if (score_mov[i] > max){
                    indice_max = i;
                    max = score_mov[i];
                }
            }
            std::cout << "déplacement suivant la commande " << indice_max << std::endl;
            switch (indice_max){
                case 0:
                    std::cout << "===> bas" << std::endl;
                    break;
                case 1:
                    std::cout << "==> gauche" << std::endl;
                    break;
                case 2:
                    std::cout << "==> droite" << std::endl;
                    break;
                case 3:
                    std::cout << "==> haut" << std::endl;
                    break;
            }
        }
        else{
            std::cout << state.list_element[character].getName() << " ne voit rien" << std::endl;
        }

        //fin check
        for (unsigned i=0; i<score_mov.size(); i++)
            if (score_mov[i] > value) {
                value = score_mov[i];

                }


        for (unsigned i=0; i<list_mov.size(); i++)
            if (score_mov[i] == value) {
                id_max_mov = i;
                break;
                }
        engine::Command command=list_mov[id_max_mov];
        command.setCharacter(character);
        engine.addCommand(command);

    }
    else {
        if(engine.att_left!=0){
            for (unsigned i=0; i<score_att.size(); i++)
                if (score_att[i] > value) {
                    value = score_att[i];

                    }

            for (unsigned i=0; i<list_att.size(); i++)
            if (score_att[i] == value) {
                id_max_att = i;
                break;
                }
            engine::Command command=list_att[id_max_att];
            command.setAttaquant(character);
            engine.addCommand(command);
                }
        }
    }



}

float distance(int x1, int y1, int x2, int y2){
    return sqrt(pow((x1-x2),2)+pow((y1-y2),2));
}
