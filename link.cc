#include "link.h"

Link::Link(int p, char id, char type, int val): player{p}, id{id}, type{type}, boosted{0}, val{val} {};

Link::~Link() {};
  
int Link::move(char d) {
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

char Link::getId() const {
  return id;
}

int Link::getPlayer() const {
  return player;
}

char Link::getType() const {
  return type;
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
  ++boosted;
};

void Link::download() {
  downloaded = true;
}