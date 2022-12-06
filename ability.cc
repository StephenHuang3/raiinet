#include "ability.h"
#include <string>
#include <iostream>

void Polarize::activate(std::shared_ptr<Player>, std::shared_ptr<Link> p, int pos){
    if ( p == nullptr ) {
        throw "You're trying to polarize nothing? interesting... \n"
        "Looks like you get another polarize! Very cool. Maybe try something new this time?";
    }
    p->changeType();

};

char Polarize::checkInput() {
    return 'l';
};

void LinkBoost::activate(std::shared_ptr<Player> player, std::shared_ptr<Link> p, int pos = 0) {
    try { 
        player->getLinks().at(p->getId());
    } catch (...) {
        throw "Boosting the opponent's link is such a silly move. That's a very you move.";
        return;
    } 
    if( p == nullptr ) {
        throw "You're trying to boost nothing? uhhhh... maybe try something else :D";
    } else {
        p->boost();
    }
};

char LinkBoost::checkInput() {
    return 'l';
};

void Firewall::activate(std::shared_ptr<Player> player, std::shared_ptr<Link> p, int pos) {};

char Firewall::checkInput() {
    return 'f';
};

void Download::activate(std::shared_ptr<Player> player, std::shared_ptr<Link> p, int pos){
    if( player->getLinks().find(p->getId()) != player->getLinks().end()) {
        throw "You can't download your own link, silly!";
    }
    if( p == nullptr ) {
        throw "uhh idk what to tell you, this isn't a link on the board bud.";
    }
    player->downloadLink(p);
};

char Download::checkInput() {
    return 'l';
};

void Scan::activate(std::shared_ptr<Player> player, std::shared_ptr<Link> p, int pos) {
    try { 
        player->getLinks().at(p->getId());
    } catch (...) {
        p->reveal();
        return;
    } 
    if( p == nullptr ) {
        throw "Scanning\n.\n.\n. nothing. Captain, what are you looking for?";
    } else {
        throw "You can already see the information on link...";
    }
    
};

char Scan::checkInput() {
    return 'l';
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

void activate(std::shared_ptr<Player> player, std::shared_ptr<Link> link, int pos) {
    
};