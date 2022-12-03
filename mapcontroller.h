#ifndef MAPCONTROLLER_H
#define MAPCONTROLLER_H

#include <iostream>
#include <map>
#include <string>
#include "subject.h"
#include "link.h"

class Board;

class Mapcontroller: public Subject {
  
  Board* theBoard;

  std::ostream &out = std::cout;

  // potential extra: round number?

public:
  explicit Mapcontroller(Board* b): theBoard{b} {};

  ~Mapcontroller(); 

  Board *&board() { return theBoard; };
  
  void reset();
  
  void render(int player);

  void moveLink(int player, char id, std::string dir);

  void useAbility(int player, int id);
  
  char getTile(int pos) const override;

  void randomize(int player);
};

#endif
