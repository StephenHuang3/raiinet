#ifndef BOARD_H
#define BOARD_H

#include <map>
#include "player.h"
#include <memory>

class Piece;

class Board {
  std::map<int, shared_ptr<Player>> players;
  std::map<int, unique_ptr<Piece>> board;

public:
  Board();
  //test 
  ~Board();

  virtual char getTile(int pos) const = 0;

  virtual bool isFirewall(int pos) const = 0;

  shared_ptr<Player> getPlayer(int p) const;
};

#endif
