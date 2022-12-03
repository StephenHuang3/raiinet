#ifndef PLAYER_H
#define PLAYER_H

#include <map>
#include <string>

class Ability;

class Player {
  // Dictionary of Abilities - tracks the number of abilities
  std::map<int, Ability*> abilities;
  std::map<int, bool> used;
  std::map<char, std::shared_ptr<Piece>> pieces;
  int data;
  int viruses;
public:
  Player();

  ~Player();
  
  void move();
  
  // sets the number of uses an ability has. I plan on having it stored in ability, but we can change that
  void setAbility(char ability, int pos);
  
  // Uses an ability
  void useAbility(int idx);

  std::string getAbilityAtPos(int pos);

  // for when link or add virus is downloaded
  void addLink();
  
  void addVirus();

  // check for win/lose
  char checkScore();

  // adds a piece to the dictionary of pieces
  void addPiece(std::shared_ptr<Piece>);

  std::map<char, std::shared_ptr<Piece>> getPieces();
};

#endif
