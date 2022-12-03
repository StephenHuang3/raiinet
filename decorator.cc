#include "decorator.h"
#include "link.h"
#include <map>

using namespace std;

Decorator::Decorator(Board* gameBoard): gB{gameBoard} {};

Decorator::~Decorator() { delete gB; };

Serverport::Serverport(Board* next, int position, int player): Decorator{next}, position{position}, player{player} {};

Serverport::~Serverport() {};

char Serverport::getTile(int pos) const {
  if( position ==  3 || position == 4 || position == 59 || position == 60) {
    return 'S';
  }
  return gB->getTile(pos);
};

bool Serverport::isFirewall(int pos) const {
  return false || gB->isFirewall(pos);
}

Firewall::Firewall(Board* next, int pos, int player): Decorator{next}, position{position}, player{player} {};

Firewall::~Firewall() {};

char Firewall::getTile(int pos) const {
  if(position == pos){
    return 'F';
  }
  
  return gB->getTile(pos);
}

bool Serverport::isFirewall(int pos) const {
  return true;
}

DisplayLinks::DisplayLinks(Board* next): Decorator{next}, theBoard{next} {};

DisplayLinks::~DisplayLinks() {};

bool DisplayLinks::isFirewall(int pos) const {
  return false;
}

char DisplayLinks::getTile(int pos) const{
  // if(theBoard->getTile(pos) == '.'){
  //   for(int i = 0; i < 8; i++){
  //     theBoard->board
  //   }
  // }
  try {
    std::shared_ptr<Link> p {theBoard->getLink(pos)};
    return p->getId();
  } catch (...) {
    return gB->getTile(pos);
  }

}
