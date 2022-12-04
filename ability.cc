#include "ability.h"
#include <string>
#include <iostream>


int Ability::getUses() {
    return uses;
}

void Polarize::activate(Player* player, std::shared_ptr<Link> p, int pos){
    p->changeType();
};

char Polarize::checkInput() {
    return 'l';
};

void LinkBoost::activate(Player* player, std::shared_ptr<Link> p, int pos = 0){
    if( player->getLinks().find(p->getId()) != player->getLinks().end()) {
        p->boost();
    }
};

char LinkBoost::checkInput() {
    return 'l';
};

void Firewall::activate(Player* player, std::shared_ptr<Link> p, int pos) {
    
};

char Firewall::checkInput() {
    return 'c';
};

void Download::activate(Player* player, std::shared_ptr<Link> p, int pos){
    if (p->getType() == 'V'){
        player->downloadVirus();
    } else {
        player->downloadData();
    }
    p->toggleDownloaded();
};

char Download::checkInput() {
    return 'l';
};

void Scan::activate(Player* player, std::shared_ptr<Link> p, int pos) { // I think we have to print this in main, because idk how this will affect the graphicobserver
    std::cout << "The link " << p->getId() << " is a " << p->getType() << " power level " << p->getVal();
}

std::string Ability::getName() {
    return name;
};

char Scan::checkInput() {
    return 'l';
};