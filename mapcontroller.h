#ifndef MAPCONTROLLER_H
#define MAPCONTROLLER_H

#include <iostream>
#include <map>
#include "subject.h"

class Board;

class Mapcontroller: public Subject {
  
  Board* theBoard;

  std::ostream &out = std::cout;

public:
  explicit Mapcontroller(Board* b): theBoard{b} {};

  ~Mapcontroller(); 

  Board *&board() { return theBoard; };
  
  void reset();
  
  void render(int player);
  
  char getTile(int pos) const override;
};

#endif
