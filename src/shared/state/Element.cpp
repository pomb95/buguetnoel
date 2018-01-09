#include <iostream>
#include "Element.h"

namespace state {
    Element::Element(){
        Name = "Element";
        PosX = 0;
        PosY = 0;
        Alive = 1;
        direction=0;
        selected=0;
      //  std::cout << Name <<" created >>";

    }

    Element::~Element() {}

    const std::string& Element::getName() const{
        return this->Name;
    }

    int Element::getPosX() const{
        return PosX;
    }

    int Element::getPosY() const{
        return PosY;
    }

    void Element::setPosX(int PosX){
        this->PosX=PosX;
    }

    void Element::setPosY(int PosY){
        this->PosY=PosY;
    }

    TypeId Element::getTypeId() const{
        return typeId;
    }

    int Element::getRange() const{
        return Range;
    }

    int Element::getLife() const {
        return Life;
    }

    void Element::setLife(int Life){
        this->Life = Life;
        }

    int Element::getTeam() const {
        return Team;
    }

    void Element::setTeam(int Team) {
        this->Team = Team;
    }

    int Element::getAlive() const {
        return Alive;
    }

    void Element::setAlive(int Alive) {
        this->Alive = Alive;
    }

    int Element::getDirection() const {
        return direction;
    }
    void Element::setDirection(int direction) {
        this->direction = direction;
    }

    int Element::getATK() const {
        return ATK;
    }
    int Element::getMovement() const {
        return Movement;
    }

    int Element::getSelected() const {
        return selected;
    }

    void Element::setATK(int ATK) {
        this->ATK = ATK;
    }

    void Element::setMovement(int Movement) {
        this->Movement=Movement;
    }

    void Element::setSelected(int selected) {
        this->selected = selected;
    }






}
