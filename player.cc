#include "player.h"
#include "ability.h"

Player::Player() {
  abilities[0] = new LinkBoost;
  abilities[1] = new Firewall;
  abilities[2] = new Download;
  abilities[3] = new Polarize;
  abilities[4] = new Scan;
  // other abilities can be added there
  links = 0;
  viruses = 0;
};

Player::~Player() {};
  
void Player::move() {}; // maybe unnecessary
  
void Player::setAbility(Ability* ability, int uses) {
  
};


void Player::useAbility(std::string ability) {
  if( true ) { // need to match string with Ability ptr somehow. I was thinking this could either be in main, or here
    // activate ability somehow
  } else {
    throw "You have no more available" + ability;
  }
};

// called when player downloads a link
void Player::addLink() {
  ++links;
};

// called when player downloads a virus
void Player::addVirus() {
  ++viruses;
};

// run to check if game ends
char Player::checkScore() {
  if( links >= 4 ) {
    return 'w'; // win
  } else if ( viruses >= 4 ) {
    return 'l'; // lose
  }
  return 'c'; // continue
};