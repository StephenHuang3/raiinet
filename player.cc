#include "player.h"
#include "ability.h"
#include <memory>
#include <iostream>

Player::Player() {
  data = 0;
  viruses = 0;
};

Player::~Player() {}

void Player::setAbility(char ability, int pos) {
  if (ability == 'L'){
    abilities[pos] = new LinkBoost;
    used[pos] = false;
  } else if (ability == 'F'){
    abilities[pos] = new Firewall;
    used[pos] = false;
  } else if (ability == 'D'){
    abilities[pos] = new Download;
    used[pos] = false;
  } else if (ability == 'S'){
    abilities[pos] = new Scan;
    used[pos] = false;
  } else if (ability == 'P'){
    abilities[pos] = new Polarize;
    used[pos] = false;
  } else {
    abilities[pos] = new LinkBoost;
    used[pos] = false;
  }
}

void Player::setUsed(int idx){
  used[idx] = true;
}


void Player::useAbility(int idx, char l, int x, int y) {
  if( abilities.at(idx)->getUses() > 0 ) { 
    if(l != ' ' && abilities.find(l) != abilities.end()) {
      abilities.at(idx)->activate(this, links.at('l'), 0);
    } else {
      abilities.at(idx)->activate(this, nullptr, x+8*y);
    }// we need to get pointer p and the pos if we need it somehow

  } else {
    throw "You have no more available";
  }
};

Ability* Player::getAbility(int idx) {
  return abilities[idx];
}

// called when player downloads a data
void Player::downloadData() {
  ++data;
};

// called when player downloads a virus
void Player::downloadVirus() {
  ++viruses;
};

// called for battle
void Player::downloadLink(std::shared_ptr<Link> link) {
    if (link->getType() == 'V'){
        this->downloadVirus();
    } else {
        this->downloadData();
    }
    link->toggleDownloaded();
}

// run to check if game ends
char Player::checkScore() {
  if( data >= 4 ) {
    return 'w'; // win
  } else if ( viruses >= 4 ) {
    return 'l'; // lose
  }
  return 'c'; // continue
};

bool Player::abilityStatusAtPos(int idx){
  return used[idx];
}

std::string Player::checkAvailable(int pos){
  std::string isused;

  if (used[pos]){
    isused = " already used";
  } else {
    isused = " not used";
  }

  std::string abilityatpos = abilities[pos]->getName();

  return abilityatpos + isused;
};

void Player::addLink(std::shared_ptr<Link> p) {
  links[p.operator*().getId()] = p;
};

std::map<char, std::shared_ptr<Link>> Player::getLinks() {
  return links;
}

int Player::getAbilityStatus() {
  int count = 0;
  for(int i = 0; i < 5; i++){
    if (used[i] == false){
      count++;
    }
  }
  return count;
}

int Player::getDataDownloaded() {
  return data;
}

int Player::getVirusesDownloaded() {
  return viruses;
}
