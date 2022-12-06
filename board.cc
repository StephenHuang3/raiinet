#include "board.h"
#include <iostream>

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

void Board::setBoard(std::map<int, std::shared_ptr<Link>> b) {
  board = b;
};

void Board::setPlayers(std::map<int, std::shared_ptr<Player>> p) {
  players = p;
};

std::map<int, std::shared_ptr<Link>> Board::getBoard() {
  return board;
};

std::map<int, std::shared_ptr<Player>> Board::getPlayers() {
  return players;
};

std::shared_ptr<Player> Board::getPlayer(int p) const {
  return players.at(p);
};

std::shared_ptr<Link> Board::getLink(int pos) const {
  return board.at(pos);
};

void Board::setLink(int p, char id, char type, int val, int position){
  // std::cout << "set " << id << ": " << type << val << " at position " << position << std::endl;
  board[position] = std::make_shared<Link>(p, position, id, type, val);
  // std::cout << "set " << board.at(position).operator*().getId() << ": " << board.at(position).operator*().getType() << board.at(position).operator*().getVal() << " at position " << position << std::endl;
  players[p].operator*().addLink(board[position]);
};

void Board::moveLink(int oldPos, int newPos) {
  board[newPos] = board[oldPos];
  board[oldPos] = nullptr;
}
