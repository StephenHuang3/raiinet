#include "observer.h"
// #include "window.h"
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

<<<<<<< HEAD
  cout << "\n========" << endl;
=======
  cout << endl << "========" << endl;
>>>>>>> 3799e7c29f888bd2d12f020e6da0d78cd0eefcde

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
// graphicObserver::~graphicObserver() {
//   theMap->detach(this);
//   delete w;
// }

// graphicObserver::graphicObserver(Mapcontroller* theMap): theMap{theMap} {
//   int width = 100 * 8 + 1;
//   int height = 100 * 8 + 1;
//   w = new Xwindow{width, height};
//   this->theMap->attach(this);
// }

// void graphicObserver::print(int player) {
//   if (player == 1){
    
//   } else {
    
//   }
// }
