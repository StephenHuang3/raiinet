#include "board.h"


Board::Board() {
  // Player List
  this->players[0] = std::make_shared<Player>();
  this->players[1] = std::make_shared<Player>();
  // std::shared_ptr<Player> a {p1};
  // this->players[0] = a;

  // std::shared_ptr<Player> b {p2};
  // this->players[1] = b;
};


// everything is deleted because of shared_ptrs
Board::~Board() {};

std::shared_ptr<Player> Board::getPlayer(int p) const {
  return players.at(p);
};

std::shared_ptr<Link> Board::getLink(int pos){
  return board.at(pos);
}

void Board::setLink(int p, char id, char type, int val, int position){
  this->board[position] = std::make_shared<Link>(p, position, id, type, val);
  players[p].operator*().addLink(board[position]);
}
