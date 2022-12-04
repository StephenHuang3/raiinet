#ifndef PLAYER_H
#define PLAYER_H

#include <map>
#include <string>

class Ability;

class Player {
  // Dictionary of Abilities - tracks the number of abilities
  std::map<int, Ability*> abilities;
  std::map<int, bool> used;
  std::map<char, std::shared_ptr<Link>> links;
  int data;
  int viruses;
public:
  Player();

  ~Player();
  
  // sets the number of uses an ability has. I plan on having it stored in ability, but we can change that
  void setAbility(char ability, int pos);
  
  // Uses an ability
  void useAbility(int idx, char l, int x, int y);

  Ability* getAbility(int idx);

  std::string checkAvailable(int pos);

  // for when link or add virus is downloaded
  void downloadData();
  
  void downloadVirus();

  int getDataDownloaded();
  int getVirusesDownloaded();
  void downloadLink(std::shared_ptr<Link> link);

  // check for win/lose
  char checkScore();

  // adds a link to the dictionary of links
  void addLink(std::shared_ptr<Link>);

  std::map<char, std::shared_ptr<Link>> getLinks();
  int getAbilityStatus();
};

#endif
