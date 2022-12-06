#include "ability.h"
#include <string>
#include <iostream>

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

void Firewall::activate(Player* player, std::shared_ptr<Link> p, int pos) {};

char Firewall::checkInput() {
    return 'f';
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
    p->reveal();
};

std::string Firewall::getName() {
    return name;
};

std::string Download::getName() {
    return name;
};

std::string Scan::getName() {
    return name;
};

std::string Polarize::getName() {
    return name;
};

std::string LinkBoost::getName() {
    return name;
};

char Scan::checkInput() {
    return 'l';
};
