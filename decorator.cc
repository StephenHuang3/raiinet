#include "decorator.h"

Decorator::Decorator(Board* gameBoard): gB{gameBoard} {};

Decorator::~Decorator() { delete gB; };

Serverport::Serverport(Board* next, int pos): Decorator{next}, pos{pos} {};

Serverport::~Serverport() {};

char Serverport::getTile(int pos) const {
  if( pos ==  3 || pos == 4 || pos == 59 || pos == 60) {
    return 'S';
  }
  return gB->getTile(pos);
};

bool Serverport::isFirewall(int pos) const {
  return false || gB->isFirewall(pos);
}

Firewall::Firewall(Board* next, int pos): Decorator{next}, pos{pos} {};

Firewall::~Firewall() {};

char Firewall::getTile(int pos) const {
  return gB->getTile(pos);
}

bool Serverport::isFirewall(int pos) const {
  return true;
}

