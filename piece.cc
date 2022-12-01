#include "piece.h"

using namespace std;

Piece::Piece(int p, string id, string type): player{p}, id{id}, type{type} {};
  
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

string Piece::getId() const {
  return id;
}

int Piece::getPlayer() const {
  return player;
}

string Piece::getType() const {
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
  val++;
}