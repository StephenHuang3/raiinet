#include "blank.h"

Blank::Blank() {};

Blank::~Blank() {};

char Blank::getTile(int pos) const {
  return '.';
}

bool Blank::isFirewall(int pos) const {
  return false;
}