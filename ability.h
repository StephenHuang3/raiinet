#ifndef ABILITY_H
#define ABILITY_H

#include "link.h"
#include "player.h"
#include <string>
#include <memory>

//class Player;
//class Link;
// may need to change to #include Link if we're using functions of Link

class Ability {

  public:
    // activates ability, if needed, we can pass a pointer to the board
    virtual void activate(std::shared_ptr<Player> player, std::shared_ptr<Link> p, int pos) = 0; // --uses

    // checks what kind and how much information we need to read in;
    virtual char checkInput() = 0;

    virtual std::string getName() = 0;
  };
  class Teleport: public Ability {
    std::string name = "Teleport";
    public:
      void activate(Player* player, std::shared_ptr<Link> p, int pos) override;
      char checkInput() override;
      std::string getName() override;
  };

  class LinkBoost: public Ability {
    std::string name = "Linkboost";
    public:
      void activate(std::shared_ptr<Player> player, std::shared_ptr<Link> p, int pos) override;
      char checkInput() override;
      std::string getName() override;
  };

  class Firewall: public Ability {
    std::string name = "Firewall";
    public:
      void activate(std::shared_ptr<Player> player, std::shared_ptr<Link> p, int pos) override;
      char checkInput() override;
      std::string getName() override;
  }; //tbd


  class Download: public Ability {
    std::string name = "Download";
    public:
      void activate(std::shared_ptr<Player> player, std::shared_ptr<Link> p, int pos) override;
      char checkInput() override;
      std::string getName() override;
  };

  class Polarize: public Ability {
    std::string name = "Polarize";
    public:
      void activate(std::shared_ptr<Player> player, std::shared_ptr<Link> p, int pos) override;
      char checkInput() override;
      std::string getName() override;
  };

  class Scan: public Ability {
    std::string name = "Scan";
    public:
      void activate(std::shared_ptr<Player> player, std::shared_ptr<Link> p, int pos) override;
      char checkInput() override;
      std::string getName() override;
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

  class Freeze: public Ability {
    std::string name = "Freeze";
    public:
      void activate(std::shared_ptr<Player> player, std::shared_ptr<Link> p, int pos) override;
      char checkInput() override;
      std::string getName() override;
  };

#endif
