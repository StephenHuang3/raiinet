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
Serverport::Serverport(Board* next, int position, int player): Decorator{next}, position{position}, player{player} {}

Serverport::~Serverport() {}

char Serverport::getTile(int pos) const {
  if( pos ==  3 || pos == 4 || pos == 59 || pos == 60) {
    return 'S';
  }
  return gB->getTile(pos);
};

int Serverport::isFirewall(int pos) const {
  return 0;
}

// FirewallTile implementation
FirewallTile::FirewallTile(Board* next, int pos, int player): Decorator{next}, position{pos}, player{player} {};

FirewallTile::~FirewallTile() {};

char FirewallTile::getTile(int pos) const {
  if (position == pos) {
    return 'F';
  }
  return gB->getTile(pos);
};

int FirewallTile::isFirewall(int pos) const {
  return player;
}

DisplayLinks::DisplayLinks(Board* next): Decorator{next}{};

DisplayLinks::~DisplayLinks() {};

int DisplayLinks::isFirewall(int pos) const {
  return 0;
}

char DisplayLinks::getTile(int pos) const{
  // if(theBoard->getTile(pos) == '.'){
  //   for(int i = 0; i < 8; i++){
  //     theBoard->board
  //   }
  // }
  // try {
  //   //cout << theBoard->getLink(pos).use_count() << endl;
  //   std::shared_ptr<Link> p {theBoard->getLink(pos)};
  //   return p->getId();
  // } catch (...) {
  //   return gB->getTile(pos);
  // }
  // try {
  //   int count = gB->getLink(pos).use_count();
  //   return 'H';
  // } catch (...){
    
  // }
  // return gB->getTile(pos);
  // cout << "in decorator displaylinks, board ptr: " << this << endl;
  // cout << pos << endl;
  // cout << this->getLink(0).operator*().getId();
  try {
    return this->getLink(pos).operator*().getId();
  } catch (...) {
    return gB->getTile(pos);
  }
}
