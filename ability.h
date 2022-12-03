#ifndef ABILITY_H
#define ABILITY_H

#include "link.h"
#include "player.h"
#include <string>

//class Player;
//class Link;
// may need to change to #include Link if we're using functions of Link

class Ability {
  std::string name;
  int uses;

  public:
    // activates ability, if needed, we can pass a pointer to the board
    virtual void activate(Player* player, Link* p, int pos) = 0; // --uses
    int getUses();
    std::string getName();
  };

  class LinkBoost: public Ability {
    public:
      void activate(Player* player, Link* p, int pos) override;
  };

  class Firewall: public Ability {
    public:
      void activate(Player* player, Link* p, int pos) override;
  }; //tbd


  class Download: public Ability {
    public:
      void activate(Player* player, Link* p, int pos) override;
  };

  class Polarize: public Ability {
    public:
      void activate(Player* player, Link* p, int pos) override;
  };

  class Scan: public Ability {
    public:
      void activate(Player* player, Link* p, int pos) override;
  };

/*
We also need to add three additional abilities.
Suggestions:
Shock - freezes an enemy link for 2 or 3 turns.
Energy Tap - permanently increase strength of ANY single link by 2 (for strategic purposes)
Randomize - scatter all links onto any positions (no overlap, none onto firewalls)
Invisibility - Make a link invisible to the opponent
Extra Turn - Allows user to take two turns in a row (2 abilities, 2 moves)
- or some similar random targetting system
- another Field ability e.g. 
*/

#endif
