#include "player.h"
#include "ability.h"
#include <memory>

Player::Player() {
  // abilities[0] = new LinkBoost;
  // abilities[1] = new Firewall;
  // abilities[2] = new Download;
  // abilities[3] = new Polarize;
  // abilities[4] = new Scan;
  // other abilities can be added there
  data = 0;
  viruses = 0;
};

Player::~Player() {};
  
void Player::move() {}; // maybe unnecessary
  

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

void Player::useAbility(std::string ability) {
  if( true ) { // need to match string with Ability ptr somehow. I was thinking this could either be in main, or here
    // activate ability somehow
  } else {
    throw "You have no more available" + ability;
  }
};

// called when player downloads a link
void Player::addLink() {
  ++data;
};

// called when player downloads a virus
void Player::addVirus() {
  ++viruses;
};

// run to check if game ends
char Player::checkScore() {
  if( data >= 4 ) {
    return 'w'; // win
  } else if ( viruses >= 4 ) {
    return 'l'; // lose
  }
  return 'c'; // continue
};

std::string Player::getAbilityAtPos(int pos){
  std::string isused;

  if (used[pos]){
    isused = " already used";
  } else {
    isused = " not used";
  }

  std::string abilityatpos = abilities[pos]->getName();

  return abilityatpos + isused;
};

void Player::addPiece(std::shared_ptr<Piece> p) {
  pieces[p.operator*().getId()] = p;
};