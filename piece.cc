#include "piece.h"

Piece::Piece(int p, char id, char type, int val): player{p}, id{id}, type{type}, boosted{0}, val{val} {};

Piece::~Piece() {};
  
int Piece::move(char d) {
  if(d == 'u') {
    return -8;
  } else if(d == 'r') {
    return 1;
  } else if(d == 'd') {
    return -8;
  } else if(d == 'l') {
    return -1;
  }
  return 0;
};

char Piece::getId() const {
  return id;
}

int Piece::getPlayer() const {
  return player;
}

char Piece::getType() const {
  return type;
}

void Piece::changeType() {
  if (type == "virus"){
    type = "data";
  } else {
    type = "virus";
  }
}

void Piece::addVal() {
  ++val;
}

int Piece::getVal() {
  return val;
}

void Piece::boost() {
  ++boosted;
}