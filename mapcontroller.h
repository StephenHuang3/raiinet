#ifndef MAPCONTROLLER_H
#define MAPCONTROLLER_H

#include <iostream>
#include <map>
#include <vector>
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
  
  void render(int turn, int endResult);

  void moveLink(int turn, char id, std::string dir);
  
  char getTile(int pos) const override;

  void randomize(int player);
};

#endif
