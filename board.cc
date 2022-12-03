#include "board.h"


Board::Board() {
  // setting the links on the default squares
  // this->board[0] = std::make_unique<Link>(1, "a");
  // this->board[1] = std::make_unique<Link>(1, "b");
  // this->board[2] = std::make_unique<Link>(1, "c");
  // this->board[11] = std::make_unique<Link>(1, "d");
  // this->board[12] = std::make_unique<Link>(1, "e");
  // this->board[5] = std::make_unique<Link>(1, "f");
  // this->board[6] = std::make_unique<Link>(1, "g");
  // this->board[7] = std::make_unique<Link>(1, "h");
  // this->board[56] = std::make_unique<Link>(1, "A");
  // this->board[57] = std::make_unique<Link>(1, "B");
  // this->board[58] = std::make_unique<Link>(1, "C");
  // this->board[51] = std::make_unique<Link>(1, "D");
  // this->board[52] = std::make_unique<Link>(1, "E");
  // this->board[61] = std::make_unique<Link>(1, "F");
  // this->board[62] = std::make_unique<Link>(1, "G");
  // this->board[63] = std::make_unique<Link>(1, "H");
  // Player List
  this->players[0] = std::make_shared<Player>();
  this->players[1] = std::make_shared<Player>();
};


// everything is deleted because of shared_ptrs
Board::~Board() {};

std::shared_ptr<Player> Board::getPlayer(int p) const {
  return players.at(p);
};
void Board::setLink(int p, char id, char type, int val, int position){
  this->board[position] = std::make_shared<Link>(p, id, type, val);
  players[p].operator*().addLink(board[position]);
}
