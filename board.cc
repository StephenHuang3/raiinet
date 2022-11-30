#include "board.h"


Board::Board() {
  this->board[0] = std::make_unique<Piece>(1, "a");
  this->board[1] = std::make_unique<Piece>(1, "b");
  this->board[2] = std::make_unique<Piece>(1, "c");
  this->board[11] = std::make_unique<Piece>(1, "d");
  this->board[12] = std::make_unique<Piece>(1, "e");
  this->board[5] = std::make_unique<Piece>(1, "f");
  this->board[6] = std::make_unique<Piece>(1, "g");
  this->board[7] = std::make_unique<Piece>(1, "h");
  this->board[56] = std::make_unique<Piece>(1, "A");
  this->board[57] = std::make_unique<Piece>(1, "B");
  this->board[58] = std::make_unique<Piece>(1, "C");
  this->board[51] = std::make_unique<Piece>(1, "D");
  this->board[52] = std::make_unique<Piece>(1, "E");
  this->board[61] = std::make_unique<Piece>(1, "F");
  this->board[62] = std::make_unique<Piece>(1, "G");
  this->board[63] = std::make_unique<Piece>(1, "H");
};

Board::~Board() {};
