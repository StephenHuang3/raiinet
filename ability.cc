#include "ability.h"
#include <string>

void Polarize::activate(Player* player, Piece* p, int pos){
    p->changeType();
}

void LinkBoost::activate(Player* player, Piece* p, int pos){
    p->boost();
}

void Download::activate(Player* oppPlayer, Piece* p, int pos){ //player here is the opponent
    if (p->getType() == "virus"){
        player->addVirus();
    } else {
        player->addLink();
    }
    delete p; //not sure if I need access to the board
}

void Scan::activate(Player* player, Piece* p, int pos) { // I think we have to print this in main, because idk how this will affect the graphicobserver
    cout << "The piece" << p->getId() << " is a " << p->getType() << " power level " << p->getVal();
}