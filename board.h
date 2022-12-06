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
  std::map<int, std::shared_ptr<Link>> getBoard();
  std::map<int, std::shared_ptr<Player>> getPlayers();
  void setBoard( std::map<int, std::shared_ptr<Link>> b );
  void setPlayers( std::map<int, std::shared_ptr<Player>> p );

  Board();

  virtual ~Board();

  virtual char getTile(int pos) const = 0;

  virtual int isFirewall(int pos) const = 0;

  std::shared_ptr<Player> getPlayer(int p) const;

  std::shared_ptr<Link> getLink(int pos) const;

  void setLink(int p, char id, char type, int val, int position);

  void moveLink(int oldPos, int newPos);
  
  std::shared_ptr<Link> findLink(char id);
};

#endif
