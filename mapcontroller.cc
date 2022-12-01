#include "mapcontroller.h"
#include "board.h"
#include "subject.h"

void Mapcontroller::reset() { 

}

void Mapcontroller::render(int player) {
  notifyObservers(player);

}


Mapcontroller::~Mapcontroller() { delete board; }

char Mapcontroller::getState(int pos) const {
  return board->getTile(pos);
}
