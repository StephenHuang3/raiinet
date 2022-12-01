#include "ability.h"
#include <string>

void Polarize::activate(Player* player, Piece* p, int pos){
    p->changeType();
}

void Download::activate(Player* player, Piece* p, int pos){ //player here is the opponent
    if (p->getType() == "virus"){
        player->addVirus();
    } else {
        player->addLink();
    }
    delete p; //not sure if I need access to the board
}

void Download::activate(Player* player, Piece* p, int pos){
    p->addVal();
}