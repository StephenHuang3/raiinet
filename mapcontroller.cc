#include "mapcontroller.h"
#include "board.h"


void Mapcontroller::reset() {};

void Mapcontroller::render(int player) {
  notifyObservers(player);
};


Mapcontroller::~Mapcontroller() { delete board; };

char Mapcontroller::getTile(int pos) const {
  return board->getTile(pos);
}
