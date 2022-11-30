#include "piece.h"

Piece::Piece(int p, std::string id, int val): player{p}, id{id}, val{val} {};
  
Piece::~Piece() {};
  
int Piece::move(char d) {
  if(d == 'u') {
    return 8;
  } else if(d == 'r') {
    return 1;
  } else if(d == 'd') {
    return -1;
  } else if(d == 'l') {
    return -8;
  }
  return 0;
};