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
  setBoard(next->getBoard()); // i think these are unnecessary
  setPlayers(next->getPlayers());
}

Serverport::~Serverport() {}

char Serverport::getTile(int pos) const {
  if(position == pos) {
    return 'S';
  }
  return gB->getTile(pos);
};

int Serverport::isFirewall(int pos) const {
  return 0 + gB->isFirewall(pos);
}

// FirewallTile implementation
FirewallTile::FirewallTile(Board* next, int pos, int player): Decorator{next}, position{pos}, player{player} {
  setBoard(next->getBoard());
  setPlayers(next->getPlayers());
  cout << "Position of links for player 1: ";
  for( auto l : getPlayer(0)->getLinks()) {
    cout << l.second->getId() << ":" << l.second->getPos() << ", ";
  }
};

FirewallTile::~FirewallTile() {};

char FirewallTile::getTile(int pos) const {
  if (position == pos) {
    if( player == 1 ) {
      return 'm';
    } else if ( player == 2 ) {
      return 'w';
    }
  }
  if(gB->getTile(pos) == 'S') {
    return 'S';
  } else {
    return '.';
  }
};

int FirewallTile::isFirewall(int pos) const {
  if(position == pos) return player;
  return 0;
}

DisplayLinks::DisplayLinks(Board* next): Decorator{next}{
  setBoard(next->getBoard());
  setPlayers(next->getPlayers());
};

DisplayLinks::~DisplayLinks() {};

int DisplayLinks::isFirewall(int pos) const {
  return 0 + gB->isFirewall(pos);
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
