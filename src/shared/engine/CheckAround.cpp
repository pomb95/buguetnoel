/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */
#include <iostream>
#include "CheckAround.h"


engine::CheckAround::CheckAround(int c) {
    character = c;
    Id = 3;
}

engine::CheckAround::~CheckAround(){
    
}

void engine::CheckAround::addElementChecked(state::Element e) {
    listElementChecked.push_back(e);
}

void engine::CheckAround::clearListelementChecked() {
    while(!listElementChecked.empty()){
        listElementChecked.pop_back();
    }
}





