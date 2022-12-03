#include "link.h"

Link::Link(int p, char id, char type, int val): player{p}, id{id}, type{type}, val{val} {};

Link::~Link() {};

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

bool Link::getDownloaded() const {
  return downloaded;
}

void Link::changeType() {
  if (type == 'V'){
    type = 'D';
  } else {
    type = 'V';
  }
};

void Link::addVal() {
  ++val;
};

int Link::getVal() {
  return val;
};

void Link::boost() {
  ++moveAmount;
};

void Link::download() {
  downloaded = true;
}