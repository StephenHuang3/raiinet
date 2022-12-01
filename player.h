#include <map>
#include <string>

class Ability;

class Player {
  // Dictionary of Abilities - tracks the number of abilities
  std::map<int, Ability*> abilities;
  int links;
  int viruses;
public:
  Player();

  ~Player();
  
  void move();
  
  // sets the number of uses an ability has. I plan on having it stored in ability, but we can change that
  void setAbility(Ability* ability, int uses);
  
  // Uses an ability
  void useAbility(std::string ability);

  // for when link or add virus is downloaded
  void addLink();
  
  void addVirus();

  // check for win/lose
  char Player::checkScore();
};