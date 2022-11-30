#include "player.h"

Player::Player() {};

Player::~Player() {};
  
void Player::move() {};
  
void Player::useAbility(std::string ability) {
  if( abilities[ability] > 0 ) {
    // ...
  } else {
    throw "You have no more available" + ability;
  }
};