#ifndef ABILITY_H
#define ABILITY_H
#include "piece.h"
#include "player.h"

#include <string>

//class Player;
//class Piece;
// may need to change to #include Piece if we're using functions of Piece

class Ability {
  std::string name;
  int uses;
public:
  // activates ability, if needed, we can pass a pointer to the board
  virtual void activate(Player* player, Piece* p, int pos) = 0; // --uses
};

class LinkBoost: public Ability {};

class Firewall: public Ability {};

class Download: public Ability {
  public:
    void activate(Player* player, Piece* p, int pos) override;
};

class Polarize: public Ability {
  public:
    void activate(Player* player, Piece* p, int pos) override;
};

class Scan: public Ability {};

/*
We also need to add three additional abilities.
Suggestions:
Freeze - freezes an enenmy piece for 2 or 3 turns.
Stim - temporary boosts the value of a piece for 2-3 turns

*/

#endif
