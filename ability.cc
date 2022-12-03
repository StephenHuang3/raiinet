#include "ability.h"
#include <string>
#include <iostream>

int Ability::getUses() {
    return uses;
}

void Polarize::activate(Player* player, Piece* p, int pos){
    p->changeType();
}

void LinkBoost::activate(Player* player, Piece* p, int pos = 0){
    if( player->getPieces().find(p->getId()) != player->getPieces().end()) {
        p->boost();
    }
}

void Download::activate(Player* player, Piece* p, int pos){
    if (p->getType() == 'V'){
        player->addVirus();
    } else {
        player->addLink();
    }
    p->download();
}

void Scan::activate(Player* player, Piece* p, int pos) { // I think we have to print this in main, because idk how this will affect the graphicobserver
    std::cout << "The piece" << p->getId() << " is a " << p->getType() << " power level " << p->getVal();
}

std::string Ability::getName() {
    return name;
}