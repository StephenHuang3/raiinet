#include "mapcontroller.h"
#include <memory>
#include "board.h"

Mapcontroller::~Mapcontroller() { delete theBoard; };

void Mapcontroller::reset() {
  
};

void Mapcontroller::render(int player) {
  notifyObservers(player);
};

void moveLink(int player, char id, std::string dir) {
  if board[id]
}

void useAbility(int player, int id) {

};

char Mapcontroller::getTile(int pos) const {
  return theBoard->getTile(pos);
};

