#ifndef MAPCONTROLLER_H
#define MAPCONTROLLER_H
#include <iostream>
#include "subject.h"
class Board;

class Mapcontroller: public Subject {
  
  Board* board;

  std::ostream &out = std::cout;

 public:
  explicit Mapcontroller(Board* board): board{board} {}

  Board *&board() { return board; }
  void reset();
  void render(int player);
  
  ~Mapcontroller();
  char getTile(int pos) const override;
};

#endif
