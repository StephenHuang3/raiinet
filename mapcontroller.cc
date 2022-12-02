#include "mapcontroller.h"
#include "board.h"

Mapcontroller::~Mapcontroller() { delete theBoard; };

void Mapcontroller::reset() {
  
};

void Mapcontroller::render(int player) {
  notifyObservers(player);
};



char Mapcontroller::getTile(int pos) const {
  return theBoard->getTile(pos);
};

