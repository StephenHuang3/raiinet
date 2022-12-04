#include "mapcontroller.h"
#include <memory>
#include "board.h"
#include <vector>
#include <cstdlib>

Mapcontroller::~Mapcontroller() { delete theBoard; };

void Mapcontroller::reset() {
  
}

void Mapcontroller::render(int player) {
  notifyObservers(player);
}

void Mapcontroller::moveLink(int player, char id, std::string dir) {
  std::shared_ptr<Player> p = theBoard->getPlayer(player);
  std::shared_ptr<Link> link = p->getLinks()[id];

  int moveAmt = link.operator*().getMoveAmount();
  if (player == 1) { moveAmt *= -1; } // multiply for -1 for Player 2 because inverted moves

  int pos = link.operator*().getPos(); // needs implementation
  // calculate new position based on direction
  int newPos = pos;
  if (dir == "up") {
    newPos += -8 * moveAmt;
  } else if (dir == "right") {
    newPos += moveAmt;
  } else if (dir == "left") {
    newPos -= moveAmt;
  } else if(dir == "down") {
    newPos += 8 * moveAmt;
  }

  // check if link is already downloaded:
  if (link.operator*().getDownloaded() == true) {
    throw 1;
  }

  // check if link will go out-of-bounds:
  int row = pos / 8;
  if ((dir == "up" || dir == "down") && (newPos < 0 || newPos > 63)) {
    throw 2;
  } else if ((dir == "right" || dir == "left") && (newPos < row * 8 || newPos > row * 8 + 7)) {
    throw 2;
  }

  // refuse if lands on own piece:
  for (auto const& ownLink : p.operator*().getLinks()) {
    if (ownLink.second.operator*().getPos() == newPos) {
      throw 3;
    }
  }

  // battle if lands on opponent:
  std::shared_ptr<Player> p2 = theBoard->getPlayer(!player);
  for (auto const& oppLink : p2.operator*().getLinks()) {
    if (oppLink.second.operator*().getPos() == newPos) {
      // battle!
      // Needs revealing and removing piece from board (possibly in download)
      if (oppLink.second.operator*().getVal() > link.operator*().getVal()) {        // lose
        p2.operator*().downloadLink(link);
      } else {                                                                      // win or tie
        p.operator*().downloadLink(oppLink.second);
      }
      return;
    }
  }

  // check if lands on firewall:
  if (theBoard->isFirewall(newPos)) {
    if( theBoard->isFirewall(newPos) != player) {
      
      if(link.operator*().getType() == 'V') {
        link.operator*().toggleDownloaded();
        theBoard->getPlayer(player).operator*().downloadVirus();
      } else {
        link.operator*().reveal();
      }
    }
    // activate firewall
    // needs removing
  }

  // check if lands on own server port:
  if (!player && (newPos == 3 || newPos == 4)) {
    throw 4;
  } else if (player && (newPos == 59 || newPos == 60)) {
    throw 4;
  }

  // check if lands on opponent server port:
  if (!player && (newPos == 59 || newPos == 60)) {
    p.operator*().downloadLink(link);
    return;
  } else if (player && (newPos == 3 || newPos == 4)) {
    std::shared_ptr<Player> p2 = theBoard->getPlayer(!player);
    p2.operator*().downloadLink(link);
    // needs removing
    return;
  }

  // otherwise, normal move: 
  link.operator*().changePos(newPos);
}

char Mapcontroller::getTile(int pos) const {
  return theBoard->getTile(pos);
}

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
    if(i == 4 || i - 1 == 5) position = i - 1 + 8; 
    theBoard->setLink(player, (char)i - 1 + 'a', type, (int)value + '0', position);
  }
}
