#ifndef BOARD_H
#define BOARD_H

#include <map>
#include "player.h"
#include <memory>
#include <string>

class Link;

class Board {
  std::map<int, std::shared_ptr<Player>> players;
  std::map<int, std::shared_ptr<Link>> board;

public:
  Board(Player* p1, Player* p2);

  ~Board();

  virtual char getTile(int pos) const = 0;

  virtual int isFirewall(int pos) const = 0;

  std::shared_ptr<Player> getPlayer(int p) const;

  std::shared_ptr<Link> getLink(int pos);

  void setLink(int p, char id, char type, int val, int position);
  
};

#endif
