#include "blank.h"

Blank::Blank() {};

Blank::~Blank() {};

char Blank::getTile(int pos) const {
  return '.';
}

int Blank::isFirewall(int pos) const {
  return 0;
}
