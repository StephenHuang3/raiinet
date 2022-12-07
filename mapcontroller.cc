#include "mapcontroller.h"
#include <memory>
#include "board.h"
#include <vector>
#include <cstdlib>
#include <iostream>

Mapcontroller::~Mapcontroller() { delete theBoard; };

void Mapcontroller::render(int player, int endResult) {
  notifyObservers(player, endResult);
}

void Mapcontroller::moveLink(int turn, char id, std::string dir) {
  int player = turn%2;
  std::shared_ptr<Player> p = theBoard->getPlayer(turn);
  
  bool yourLink = false;
  for( auto const& l : p->getLinks() ) {
    if( l.second->getId() == id) yourLink = true;
  }
  if( !yourLink ) throw "Dumdum Alert: Ayo tf you doin?? You can't move a piece that aint yours, or something, idk.";
  std::shared_ptr<Link> link = p->getLinks().at(id);
  if( turn - link->getFrozen() < 11) {
    throw "Brrrr, strap out, it's really cold here. Looks like this link is going to be waiting here a while";
  }
  int moveAmt = link->getMoveAmount();
  if (player == 1) { moveAmt *= -1; } // multiply for -1 for Player 2 because inverted moves

  int pos = link->getPos();
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
  } else {
    throw "NewbNewb Alert: use up, right, down, or left to move the piece";
  }

  // check if link is already downloaded:
  if (link->getDownloaded() == true) {
    throw "That link is already downloaded.";
  }

  // check if link will go out-of-bounds:
  int row = pos / 8;
  if ((dir == "up" || dir == "down") && ((newPos < 0)|| (newPos > 63))) {
    if(newPos > 63 && player == 0) {
      p->downloadLink(link);
    } else if (newPos < 0 && player == 1) {
      p->downloadLink(link);
    } else {
      throw "Watch out! The Earth is flat! You don't want your link to fall off the edge!";
    }
  } else if ((dir == "right" || dir == "left") && (newPos < row * 8 || newPos > row * 8 + 7)) {
    throw "Watch out! The Earth is flat! You don't want your link to fall off the edge!";
  }

  // refuse if lands on own piece:
  for (auto const& ownLink : p->getLinks()) {
    if (ownLink.second->getPos() == newPos && ownLink.second->getDownloaded() == false) {
      throw "You cannot move links onto your own links.";
    }
  }

  // battle if lands on opponent:
  bool captured = false;
  std::shared_ptr<Player> p2 = theBoard->getPlayer(!player);
  for (auto const& oppLink : p2->getLinks()) {
    if (oppLink.second->getPos() == newPos && oppLink.second->getDownloaded() == false) {
      // battle!
      // Needs revealing and removing piece from board (possibly in download)
      if (oppLink.second->getVal() > link->getVal()) {        // lose
        p2->downloadLink(link);
        captured = true;
        oppLink.second->reveal();
      } else {                                                // win or tie
        p->downloadLink(oppLink.second);
        link->reveal();
      }
      break;
    }
  }

  // check if lands on firewall:
  if (theBoard->isFirewall(newPos) > 0) {
    std::cout << newPos << "is a firewall " << theBoard->isFirewall(newPos) << std::endl;
    if( theBoard->isFirewall(newPos) != player + 1) {
      if(link->getType() == 'V') {
        link->toggleDownloaded();
        theBoard->getPlayer(player)->downloadVirus();
      } else {
        link->reveal();
      }
    }
    // activate firewall
    // needs removing
  }

  // check if lands on own server port:
  if ((player+1)%2 && (newPos == 3 || newPos == 4)) {
    throw "You cannot move links onto your own server ports.";
  } else if ((player+1)%2 && (newPos == 59 || newPos == 60)) {
    throw "You cannot move links onto your own server ports.";
  }

  // check if lands on opponent server port:
  if ((player+1)%2 && (newPos == 59 || newPos == 60)) {
    p->downloadLink(link);
    return;
  } else if (player && (newPos == 3 || newPos == 4)) {
    std::shared_ptr<Player> p2 = theBoard->getPlayer(!player);
    p2->downloadLink(link);
    // needs removing
    return;
  }

  // otherwise, normal move: 
  if(!captured) {
    link->changePos(newPos);
    theBoard->moveLink(pos, newPos);
  }
}

char Mapcontroller::getTile(int pos) const {
  return theBoard->getTile(pos);
}

void Mapcontroller::randomize(int player) {
  // std::cout << theBoard << std::endl;
  std::map<int, std::string> m = {{0, "D1"}, {1, "D2"}, {2, "D3"}, {3, "D4"}, 
                                  {4, "V1"}, {5, "V2"}, {6, "V3"}, {7, "V4"}};
  for(int i = 8; i > 0; --i) {
    int idx = rand() % i;
    std::string name = m[idx];
    char type = name[0];
    char value = name[1];
    m.erase(idx);
    for(int j = idx; j < i - 1; ++j) {
      m[j] = m[j + 1];
    }
    m.erase(i - 1);

    if (player == 0) {
      int position = i - 1;
      if(i == 4 || i == 5) position += 8; 
      theBoard->setLink(player, (char)(i - 1 + 97), type, (int)value - 48, position);
    } else {
      int position = i - 1 + 56;
      if(i == 4 || i == 5) position -= 8;
      theBoard->setLink(player, (char)(i - 1 + 65), type, (int)value - 48, position);
    }
  }
}
