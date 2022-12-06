#include "decorator.h"
#include "link.h"
#include <map>
#include <memory>
#include <iostream>

using namespace std;

// Decorator implementation
Decorator::Decorator(Board* gameBoard): gB{gameBoard} {}
Decorator::~Decorator() { delete gB; };

// Serverport implementation
Serverport::Serverport(Board* next, int position, int player): Decorator{next}, position{position}, player{player} {
  setBoard(next->getBoard());
  setPlayers(next->getPlayers());
}

Serverport::~Serverport() {}

char Serverport::getTile(int pos) const {
  if( pos ==  3 || pos == 4 || pos == 59 || pos == 60) {
    return 'S';
  }
  return gB->getTile(pos);
};

int Serverport::isFirewall(int pos) const {
  return -1;
}

// FirewallTile implementation
FirewallTile::FirewallTile(Board* next, int pos, int player): Decorator{next}, position{pos}, player{player} {
  setBoard(next->getBoard());
  setPlayers(next->getPlayers());
};

FirewallTile::~FirewallTile() {};

char FirewallTile::getTile(int pos) const {
  if (position == pos) {
    if( player == 0 ) {
      return 'm';
    } else if ( player == 1 ) {
      return 'w';
    }
  }
  return gB->getTile(pos);
};

int FirewallTile::isFirewall(int pos) const {
  return player;
}

DisplayLinks::DisplayLinks(Board* next): Decorator{next}{
  setBoard(next->getBoard());
  setPlayers(next->getPlayers());
};

DisplayLinks::~DisplayLinks() {};

int DisplayLinks::isFirewall(int pos) const {
  return -1;
}

char DisplayLinks::getTile(int pos) const{

  try {
    shared_ptr<Link> p = this->getLink(pos);
    if(p == nullptr) {
      throw 1;
    }
    if(p->getDownloaded() == true) {
      throw 2;
    }
    return p->getId();
  } catch (...) {
    return gB->getTile(pos);
  }
}
