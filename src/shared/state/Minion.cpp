/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

#include "Minion.h"
#include "MinionStatus.h"

namespace state {

    Minion::Minion(): m_LP(100), m_MP(4), m_ATK(5), m_DEF(0), m_RANGE(1) {

    }

    Minion::~Minion() {

    }

    const TypeId Minion::getTypeId() {
   
    }

    MinionStatus Minion::getStatus() const {
        return this->status;
    }

    const bool Minion::isHero() {

    }

    void Minion::setStatus(MinionStatus status) {
        this->status = status;
    }

}