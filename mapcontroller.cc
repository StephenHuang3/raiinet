#include "mapcontroller.h"
#include <memory>
#include "board.h"
#include <vector>
#include <cstdlib>

Mapcontroller::~Mapcontroller() { delete theBoard; };

void Mapcontroller::reset() {
  
};

void Mapcontroller::render(int player) {
  notifyObservers(player);
};

void useAbility(int player, int id) {

};

char Mapcontroller::getTile(int pos) const {
  return theBoard->getTile(pos);
};

void Mapcontroller::randomize(int player) {
  std::map<int, std::string> m = {{0, "D1"}, {1, "D2"}, {2, "D3"}, {3, "D4"}, 
                                  {4, "V1"}, {5, "V2"}, {6, "V3"}, {7, "V4"}};
  for(int i = 8; i > 1; --i) {
    int idx = rand() % i;
    std::string name = m[idx];
    char type = name[0];
    char value = name[1];
    m.erase(idx);
    for(int j = idx; j < i - 1; ++j) {
      m[j] = m[j + 1];
    }
    m.erase(i - 1);
    int position = i - 1;
    if(i == 5 || i - 1 == 6) position = i - 1 + 8; 
    theBoard->setPiece(player, (char)i - 1 + 'a', type, (int)value + '0', position);
  }
};
