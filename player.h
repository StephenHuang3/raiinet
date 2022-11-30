#include <map>
#include <string>

class Ability;

class Player {
  // Dictionary of Abilities - tracks the number of abilities
  std::map<std::string, int> abilities;
public:
  Player();

  ~Player();
  
  void move();
  
  // Uses an ability
  void useAbility(std::string ability);
}