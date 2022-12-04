#include "link.h"

Link::Link(int p, int pos, char id, char type, int val): player{p}, pos{pos}, id{id}, type{type}, val{val} {};

Link::~Link() {};

int Link::getPos() const {
  return pos;
}

char Link::getId() const {
  return id;
}

int Link::getPlayer() const {
  return player;
}

char Link::getType() const {
  return type;
}

int Link::getMoveAmount() const {
  return moveAmount;
}

int Link::getVal() const {
  return val;
}

bool Link::getDownloaded() const {
  return downloaded;
}

bool Link::getRevealed() const {
  return revealed;
}

void Link::changeType() {
  if (type == 'V'){
    type = 'D';
  } else {
    type = 'V';
  }
}

void Link::changePos(int newPos) {
  pos = newPos;
}

void Link::addVal() {
  ++val;
}

void Link::boost() {
  ++moveAmount;
}

void Link::toggleDownloaded() {
  downloaded = true;
}

void Link::reveal() {
  revealed = true;
}
