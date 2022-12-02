#ifndef BOARD_H
#define BOARD_H

#include <map>
#include "player.h"
#include <memory>
#include <string>
using namespace std;

class Piece;

class Board {
  std::map<int, std::unique_ptr<Player>> players;
  std::map<int, std::unique_ptr<Piece>> board;

public:
  Board();
  //test 
  ~Board();
  
  virtual char getTile(int pos) const = 0;

  virtual bool isFirewall(int pos) const = 0;

  std::unique_ptr<Player> getPlayer1() {this->players[0];};
  std::unique_ptr<Player> getPlayer2() {this->players[1];};

  void setPiece(int p, char id, string type, int val, int position);
  
};

#endif
