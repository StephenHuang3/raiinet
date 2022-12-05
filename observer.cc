#include "observer.h"
#include "window.h"
#include "mapcontroller.h"
#include "subject.h"
#include "player.h"

using namespace std;

textObserver::textObserver(Mapcontroller* theMap): theMap{theMap} {
  theMap->attach(this);
}

textObserver::~textObserver() {
  theMap->detach(this);
}

void textObserver::print(int player){
  map<char, shared_ptr<Link>> yourLinks = theMap->board()->getPlayer(player)->getLinks();
  map<char, shared_ptr<Link>> enemyLinks = theMap->board()->getPlayer(!player)->getLinks();
  
  int asciivalue;
  if (player == 0) {
    asciivalue = 97;
  } else if (player == 1) {
    asciivalue = 65;
  }

  cout << "Player " << player + 1 << ":" << endl;
  cout << "Downloaded: " << theMap->board()->getPlayer(player)->getDataDownloaded() << "D, " << theMap->board()->getPlayer(player)->getVirusesDownloaded() << "V" << endl;
  cout << "Abilities: " << theMap->board()->getPlayer(player)->getAbilityStatus() << endl;

  for (int i = 0; i < 8; i++){
    if (i == 4){
      cout << endl;
    }
      char c = static_cast<char> (asciivalue + i);
      cout << c << ": " << yourLinks[c]->getType() << yourLinks[c]->getVal() << " ";
  }

  cout << "\n========" << endl;

  // Print depending on player
  if (player == 0) {
    for( int i = 0; i < 8; ++i) {
      for( int j = 0; j < 8; ++j) {
        cout << theMap->getTile(i*8 + j);
      }
      cout << endl;
    }
  } else if (player == 1){
    for( int i = 7; i >= 0; --i) {
      for( int j = 7; j >= 0; --j) {
        cout << theMap->getTile(i*8 + j);
      }
      cout << endl;
    }
  }

  cout << "========" << endl;

  if (player == 0) {
    cout << "Player 2:" << endl;
  } else if (player == 1) {
    cout << "Player 1:" << endl;
  }
  cout << "Downloaded: " << theMap->board()->getPlayer(!player)->getDataDownloaded() << "D, " << theMap->board()->getPlayer(!player)->getVirusesDownloaded() << "V" << endl;
  cout << "Abilities: " << theMap->board()->getPlayer(!player)->getAbilityStatus() << endl;

  if(player == 0){
    asciivalue = 65;
  } else if (player == 1){
    asciivalue = 97;
  }

  for (int i = 0; i < 8; i++){
    if (i == 4){
      cout << endl;
    }
      char c = static_cast<char> (asciivalue + i);
      if (enemyLinks[c]->getDownloaded()) {
        cout << c << ": " << enemyLinks[c]->getType() << enemyLinks[c]->getVal() << " ";
      } else {
        cout << c << ": ?  ";
      }
  }

  cout << endl;  
}
graphicObserver::~graphicObserver() {
  theMap->detach(this);
  delete w;
}

graphicObserver::graphicObserver(Mapcontroller* theMap): theMap{theMap} {
  int width = 300;
  int height = 300;
  w = new Xwindow{width, height};
  this->theMap->attach(this);
}

void graphicObserver::print(int player) {
  map<char, shared_ptr<Link>> yourLinks = theMap->board()->getPlayer(player)->getLinks();
  map<char, shared_ptr<Link>> enemyLinks = theMap->board()->getPlayer(!player)->getLinks();

  w->drawString(0, 10, "Player " + std::to_string(player + 1) + "1:");

  w->drawString(0, 25, "Downloaded: " + std::to_string(theMap->board()->getPlayer(player)->getDataDownloaded()) + "D, " + std::to_string(theMap->board()->getPlayer(player)->getVirusesDownloaded()) + "V");

  w->drawString(0, 40, "Abilities: " + std::to_string(theMap->board()->getPlayer(player)->getAbilityStatus()));

  w->drawString(0, 55, "a: V1 b: D4 c: V3 d: V2");

  w->drawString(0, 70, "e: D3 f: V4 g: D2 h: D1");

  for (int i = 0; i < 8; ++i) {
    for (int j = 0; j < 8; ++j) {
      if (i == 0) {
        if (j == 0 || j == 2 || j == 5) {
          w->fillRectangle(10 * j, 85 + 10 * i, 10, 10, Xwindow::Red);
          continue;
        } else if (j == 3 || j == 4) {
          w->fillRectangle(10 * j, 85 + 10 * i, 10, 10, Xwindow::Black);
          continue;
        } else {
          w->fillRectangle(10 * j, 85 + 10 * i, 10, 10, Xwindow::Green);
          continue;
        }
      }
      if (i == 1 && j == 3) {
        w->fillRectangle(10 * j, 85 + 10 * i, 10, 10, Xwindow::Red);
        continue;
      }
      if (i == 1 && j == 4) {
        w->fillRectangle(10 * j, 85 + 10 * i, 10, 10, Xwindow::Green);
        continue;
      }
      if (((i == 6) && (j == 3)) || ((i == 6) && (j == 4))) {
        w->fillRectangle(10 * j, 85 + 10 * i, 10, 10, Xwindow::Brown);
        continue;
      }
      if (i == 7) {
        if ((j != 3) && (j != 4)) {
          w->fillRectangle(10 * j, 85 + 10 * i, 10, 10, Xwindow::Brown);
          continue;
        } else {
          w->fillRectangle(10 * j, 85 + 10 * i, 10, 10, Xwindow::Black);
          continue;
        }
      }
      w->fillRectangle(10 * j, 85 + 10 * i, 10, 10, Xwindow::White);
    }
  }

  w->drawString(0, 180, "Player 2:");

  w->drawString(0, 195, "Downloaded: 0D, 0V");

  w->drawString(0, 210, "Abilities: 5");

  w->drawString(0, 225, "A: ? B: ? C: ? D: ?");

  w->drawString(0, 240, "E: ? F: ? G: ? H: ?");

  char c;
  cin >> c;
}
