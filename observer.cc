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
  int width = 600;
  int height = 500;
  w = new Xwindow{width, height};
  this->theMap->attach(this);
}

void graphicObserver::print(int player) {
  map<char, shared_ptr<Link>> yourLinks = theMap->board()->getPlayer(player)->getLinks();
  map<char, shared_ptr<Link>> enemyLinks = theMap->board()->getPlayer(!player)->getLinks();

  // Initial print for Player 1:
  if (turn == 1) {
    // Printing background items
    w->fillRectangle(8, 8, 584, 484, 1); // frame
    w->fillRectangle(13, 13, 574, 474, 5); // bgcolor
    w->drawString(264, 34, "Welcome to");

    // Printing the logo
    int lX = 209;
    int lY = 48;
    int c = 1;
    // R
    w->fillRectangle(lX, lY, 6, 33, c);
    w->fillRectangle(lX + 6, lY, 12, 6, c);
    w->fillRectangle(lX + 18, lY + 3, 3, 3, c);
    w->fillRectangle(lX + 18, lY + 6, 6, 9, c);
    w->fillRectangle(lX + 18, lY + 15, 3, 3, c);
    w->fillRectangle(lX + 6, lY + 15, 12, 6, c);
    w->fillRectangle(lX + 12, lY + 21, 9, 3, c);
    w->fillRectangle(lX + 15, lY + 24, 6, 3, c);
    w->fillRectangle(lX + 18, lY + 27, 6, 6, c);
    // A
    w->fillRectangle(lX + 27, lY + 12, 6, 21, c);
    w->fillRectangle(lX + 30, lY + 6, 6, 6, c);
    w->fillRectangle(lX + 33, lY + 3, 3, 3, c);
    w->fillRectangle(lX + 36, lY, 6, 6, c);
    w->fillRectangle(lX + 42, lY + 3, 3, 3, c);
    w->fillRectangle(lX + 42, lY + 6, 6, 6, c);
    w->fillRectangle(lX + 45, lY + 12, 6, 21, c);
    w->fillRectangle(lX + 33, lY + 18, 12, 6, c);
    // I
    w->fillRectangle(lX + 54, lY, 18, 3, c);
    w->fillRectangle(lX + 57, lY + 3, 12, 3, c);
    w->fillRectangle(lX + 60, lY, 6, 33, c);
    w->fillRectangle(lX + 57, lY + 27, 12, 3, c);
    w->fillRectangle(lX + 54, lY + 30, 18, 3, c);
    // Second I
    w->fillRectangle(lX + 75, lY, 18, 3, c);
    w->fillRectangle(lX + 78, lY + 3, 12, 3, c);
    w->fillRectangle(lX + 81, lY, 6, 33, c);
    w->fillRectangle(lX + 78, lY + 27, 12, 3, c);
    w->fillRectangle(lX + 75, lY + 30, 18, 3, c);
    // N
    w->fillRectangle(lX + 96, lY, 6, 33, c);
    w->fillRectangle(lX + 102, lY + 3, 3, 9, c);
    w->fillRectangle(lX + 105, lY + 9, 3, 9, c);
    w->fillRectangle(lX + 108, lY + 12, 3, 9, c);
    w->fillRectangle(lX + 111, lY + 18, 3, 9, c);
    w->fillRectangle(lX + 114, lY + 21, 3, 9, c);
    w->fillRectangle(lX + 117, lY, 6, 33, c);
    // E
    w->fillRectangle(lX + 126, lY, 6, 33, c);
    w->fillRectangle(lX + 132, lY, 15, 6, c);
    w->fillRectangle(lX + 144, lY + 6, 3, 3, c);
    w->fillRectangle(lX + 132, lY + 12, 12, 6, c);
    //w->fillRectangle(lX + 141, lY + 12, 3, 3, c);
    w->fillRectangle(lX + 144, lY + 24, 3, 3, c);
    w->fillRectangle(lX + 132, lY + 27, 15, 6, c);
    // T
    w->fillRectangle(lX + 150, lY, 24, 3, c);
    w->fillRectangle(lX + 153, lY + 3, 18, 3, c);
    w->fillRectangle(lX + 159, lY, 6, 33, c);

    // int brdX = 170;
    // int brdY = 187;

    // Print legend
    int legOffset = 18;
    int legX = 435;
    int legY = 205;
    w->fillRectangle(legX + 20, 194, 35, 2, 1);
    w->drawString(legX + 20, 192, "Legend");

    w->fillRectangle(legX, legY, 10, 10, 3);
    w->drawString(legX + 20, legY + 10, "Data");
    w->fillRectangle(legX, legY + legOffset, 10, 10, 2);
    w->drawString(legX + 20, legY + 10 + legOffset, "Virus");
    w->fillRectangle(legX, legY + 2 * legOffset, 10, 10, 1);
    w->drawString(legX + 20, legY + 10 + 2 * legOffset, "Server Port");
    w->fillRectangle(legX, legY + 3 * legOffset, 10, 10, 4);
    w->drawString(legX + 20, legY + 10 + 3 * legOffset, "Firewall");
    w->fillRectangle(legX, legY + 4 * legOffset, 10, 10, 7);
    w->drawString(legX + 20, legY + 10 + 4 * legOffset, "Enemy Unknown");
    w->fillRectangle(legX, legY + 5 * legOffset, 10, 10, 6);
    w->drawString(legX + 20, legY + 10 + 5 * legOffset, "Enemy Data");
    w->fillRectangle(legX, legY + 6 * legOffset, 10, 10, 8);
    w->drawString(legX + 20, legY + 10 + 6 * legOffset, "Enemy Virus");
    

    // Current player background
    w->fillRectangle(brdX - 4, brdY - 82, 191, 68, 4);
    w->fillRectangle(brdX - 2, brdY - 80, 187, 64, 6);

    w->drawString(brdX + 15, brdY - 60, "Player 1:");
    w->drawString(brdX + 15, brdY - 44, "Downloaded:  " + std::to_string(theMap->board()->getPlayer(0)->getDataDownloaded()) + "    " + std::to_string(theMap->board()->getPlayer(0)->getVirusesDownloaded()));
    w->fillRectangle(brdX + 102, brdY - 53, 10, 10, 1);
    w->fillRectangle(brdX + 103, brdY - 52, 8, 8, 3);
    w->fillRectangle(brdX + 132, brdY - 53, 10, 10, 1);
    w->fillRectangle(brdX + 133, brdY - 52, 8, 8, 2);
    w->drawString(brdX + 15, brdY - 28, "Abilities: " + std::to_string(theMap->board()->getPlayer(0)->getAbilityStatus()));
    
    // Board
    // cd b ea
    w->fillRectangle(brdX - 4, brdY - 2, 191, 191, 10); // grey board background
    for (int i = 0; i < 8; ++i) {
      for (int j = 0; j < 8; ++j) {
        char c = theMap->board()->getTile(j + 8 * i);
        if (c == '.') {
          w->fillRectangle(brdX + 23 * j, brdY + 23 * i + 2, 22, 22, 0); // white
        } else if (c == 'S') {
          w->fillRectangle(brdX + 23 * j, brdY + 23 * i + 2, 22, 22, 1); // black
        } else if (c <= 'h' && c >= 'a') {
          if (theMap->board()->getPlayer(0)->getLinks().at(c)->getType() == 'V') { // virus
            w->fillRectangle(brdX + 23 * j, brdY + 23 * i + 2, 22, 22, 2); // red
          } else { // data
            w->fillRectangle(brdX + 23 * j, brdY + 23 * i + 2, 22, 22, 3); // green
          }
          w->drawString(brdX + 23 * j + 6, brdY + 23 * i + 2 + 15, std::string(1, c) + std::to_string(theMap->board()->getPlayer(0)->getLinks().at(c)->getVal()));
        } else if (c >= 'A' && c <= 'H') { // opponent links
          w->fillRectangle(brdX + 23 * j, brdY + 23 * i + 2, 22, 22, 7); // magenta
          w->drawString(brdX + 23 * j + 9, brdY + 23 * i + 2 + 15, std::string(1, c));
        } else { // firewall
          w->fillRectangle(brdX + 23 * j, brdY + 23 * i + 2, 22, 22, 4); // blue
        }
      }
    } 
    // Other player background
    w->fillRectangle(brdX - 4, brdY + 202, 191, 68, 2);
    w->fillRectangle(brdX - 2, brdY + 204, 187, 64, 6);

    w->drawString(brdX + 15, brdY + 224, "Player 2:");
    w->drawString(brdX + 15, brdY + 240, "Downloaded:  " + std::to_string(theMap->board()->getPlayer(1)->getDataDownloaded()) + "    " + std::to_string(theMap->board()->getPlayer(1)->getVirusesDownloaded()));
    w->fillRectangle(brdX + 102, brdY + 231, 10, 10, 1);
    w->fillRectangle(brdX + 103, brdY + 232, 8, 8, 3);
    w->fillRectangle(brdX + 132, brdY + 231, 10, 10, 1);
    w->fillRectangle(brdX + 133, brdY + 232, 8, 8, 2);
    w->drawString(brdX + 15, brdY + 256, "Abilities: " + std::to_string(theMap->board()->getPlayer(1)->getAbilityStatus()));
    
  } else {

    // Reprint after resetting
    if (turn % 2 == 1) {
    w->fillRectangle(brdX - 4, brdY - 82, 191, 68, 4);
    w->fillRectangle(brdX - 2, brdY - 80, 187, 64, 6);
    w->drawString(brdX + 15, brdY - 60, "Player 1:");
    w->drawString(brdX + 15, brdY - 44, "Downloaded:  " + std::to_string(theMap->board()->getPlayer(0)->getDataDownloaded()) + "    " + std::to_string(theMap->board()->getPlayer(0)->getVirusesDownloaded()));
    w->fillRectangle(brdX + 102, brdY - 53, 10, 10, 1);
    w->fillRectangle(brdX + 103, brdY - 52, 8, 8, 3);
    w->fillRectangle(brdX + 132, brdY - 53, 10, 10, 1);
    w->fillRectangle(brdX + 133, brdY - 52, 8, 8, 2);
    w->drawString(brdX + 15, brdY - 28, "Abilities: " + std::to_string(theMap->board()->getPlayer(0)->getAbilityStatus()));
    
    // Other player
    w->fillRectangle(brdX - 4, brdY + 202, 191, 68, 2);
    w->fillRectangle(brdX - 2, brdY + 204, 187, 64, 6);
    w->drawString(brdX + 15, brdY + 224, "Player 2:");
    w->drawString(brdX + 15, brdY + 240, "Downloaded:  " + std::to_string(theMap->board()->getPlayer(1)->getDataDownloaded()) + "    " + std::to_string(theMap->board()->getPlayer(1)->getVirusesDownloaded()));
    w->fillRectangle(brdX + 102, brdY + 231, 10, 10, 1);
    w->fillRectangle(brdX + 103, brdY + 232, 8, 8, 3);
    w->fillRectangle(brdX + 132, brdY + 231, 10, 10, 1);
    w->fillRectangle(brdX + 133, brdY + 232, 8, 8, 2);
    w->drawString(brdX + 15, brdY + 256, "Abilities: " + std::to_string(theMap->board()->getPlayer(1)->getAbilityStatus()));
    
    } else {
    w->fillRectangle(brdX - 4, brdY - 82, 191, 68, 2);
    w->fillRectangle(brdX - 2, brdY - 80, 187, 64, 6);
    w->drawString(brdX + 15, brdY - 60, "Player 2:");
    w->drawString(brdX + 15, brdY - 44, "Downloaded:  " + std::to_string(theMap->board()->getPlayer(1)->getDataDownloaded()) + "    " + std::to_string(theMap->board()->getPlayer(1)->getVirusesDownloaded()));
    w->fillRectangle(brdX + 102, brdY - 53, 10, 10, 1);
    w->fillRectangle(brdX + 103, brdY - 52, 8, 8, 3);
    w->fillRectangle(brdX + 132, brdY - 53, 10, 10, 1);
    w->fillRectangle(brdX + 133, brdY - 52, 8, 8, 2);
    w->drawString(brdX + 15, brdY - 28, "Abilities: " + std::to_string(theMap->board()->getPlayer(1)->getAbilityStatus()));
    
      // Other player
      w->fillRectangle(brdX - 4, brdY + 202, 191, 68, 4);
      w->fillRectangle(brdX - 2, brdY + 204, 187, 64, 6);
      w->drawString(brdX + 15, brdY + 224, "Player 1:");
      w->drawString(brdX + 15, brdY + 240, "Downloaded:  " + std::to_string(theMap->board()->getPlayer(0)->getDataDownloaded()) + "    " + std::to_string(theMap->board()->getPlayer(0)->getVirusesDownloaded()));
      w->fillRectangle(brdX + 102, brdY + 231, 10, 10, 1);
      w->fillRectangle(brdX + 103, brdY + 232, 8, 8, 3);
      w->fillRectangle(brdX + 132, brdY + 231, 10, 10, 1);
      w->fillRectangle(brdX + 133, brdY + 232, 8, 8, 2);
      w->drawString(brdX + 15, brdY + 256, "Abilities: " + std::to_string(theMap->board()->getPlayer(0)->getAbilityStatus()));
    }

    // Reset the board and reprint
    w->fillRectangle(brdX - 4, brdY - 2, 191, 191, 10); // grey board background
    for (int i = 0; i < 8; ++i) {
      for (int j = 0; j < 8; ++j) {
        char c;
        (player == 0) ? c = theMap->board()->getTile(j + 8 * i) : c = theMap->board()->getTile(63 - j - 8 * i);
        if (c == '.') {
          w->fillRectangle(brdX + 23 * j, brdY + 23 * i + 2, 22, 22, 0);
        } else if (c == 'S') {
          w->fillRectangle(brdX + 23 * j, brdY + 23 * i + 2, 22, 22, 1);

        } else if (c <= 'h' && c >= 'a') {
          if (player == 0) {
            if (theMap->board()->getPlayer(0)->getLinks().at(c)->getType() == 'V') { // virus
              w->fillRectangle(brdX + 23 * j, brdY + 23 * i + 2, 22, 22, 2);
            } else { // data
              w->fillRectangle(brdX + 23 * j, brdY + 23 * i + 2, 22, 22, 3);
            }
            w->drawString(brdX + 23 * j + 6, brdY + 23 * i + 2 + 15, std::string(1, c) + std::to_string(theMap->board()->getPlayer(0)->getLinks().at(c)->getVal()));
          } else { // checks for revealed
            if (theMap->board()->getPlayer(0)->getLinks().at(c)->getRevealed() == true) {
              if (theMap->board()->getPlayer(0)->getLinks().at(c)->getType() == 'V') {
                w->fillRectangle(brdX + 23 * j, brdY + 23 * i + 2, 22, 22, 8); // orange
              } else {
                w->fillRectangle(brdX + 23 * j, brdY + 23 * i + 2, 22, 22, 6); // yellow
              }
            } else {
              w->fillRectangle(brdX + 23 * j, brdY + 23 * i + 2, 22, 22, 7); // magenta
              w->drawString(brdX + 23 * j + 9, brdY + 23 * i + 2 + 15, std::string(1, c));
            }
          }

        } else if (c >= 'A' && c <= 'H') { // opponent links
          if (player == 1) {
            if (theMap->board()->getPlayer(1)->getLinks().at(c)->getType() == 'V') { // virus
              w->fillRectangle(brdX + 23 * j, brdY + 23 * i + 2, 22, 22, 2);
            } else { // data
              w->fillRectangle(brdX + 23 * j, brdY + 23 * i + 2, 22, 22, 3);
            }
            w->drawString(brdX + 23 * j + 6, brdY + 23 * i + 2 + 15, std::string(1, c) + std::to_string(theMap->board()->getPlayer(1)->getLinks().at(c)->getVal()));
          } else { // checks for revealed
            if (theMap->board()->getPlayer(1)->getLinks().at(c)->getRevealed() == true) {
              if (theMap->board()->getPlayer(1)->getLinks().at(c)->getType() == 'V') {
                w->fillRectangle(brdX + 23 * j, brdY + 23 * i + 2, 22, 22, 8); // orange
              } else {
                w->fillRectangle(brdX + 23 * j, brdY + 23 * i + 2, 22, 22, 6); // yellow
              }
            } else {
              w->fillRectangle(brdX + 23 * j, brdY + 23 * i + 2, 22, 22, 7); // magenta
              w->drawString(brdX + 23 * j + 9, brdY + 23 * i + 2 + 15, std::string(1, c));
            }
          }

        } else { // firewall
          w->fillRectangle(brdX + 23 * j, brdY + 23 * i + 2, 22, 22, 4); // blue
        }
      }
    }
  }
  // for (int i = 0; i < 8; ++i) {
  //   for (int j = 0; j < 8; ++j) {
  //     char c = theMap->board()->getTile(j + 8 * i);
  //     if (c == '.') {
  //       w->fillRectangle(5 + 10 * j, 85 + 10 * i, 10, 10, 0); // white
  //     } else if (c == 'S') {
  //       w->fillRectangle(5 + 10 * j, 85 + 10 * i, 10, 10, 1); // black
  //     } else if (c <= 'h' && c >= 'a') {
  //       if (player == 0) {
  //         if (theMap->board()->getPlayer(player)->getLinks().at(c)->getType() == 'V') { // virus
  //           w->fillRectangle(5 + 10 * j, 85 + 10 * i, 10, 10, 2); // red
  //         } else { // data
  //           w->fillRectangle(5 + 10 * j, 85 + 10 * i, 10, 10, 3); // green
  //         }
  //       } else { // needs if reveal
  //         w->fillRectangle(5 + 10 * j, 85 + 10 * i, 10, 10, 4); // black
  //       }
  //     } else if (c >= 'A' && c <= 'H') {
  //       if (player == 1) {
  //         if (theMap->board()->getPlayer(player)->getLinks().at(c)->getType() == 'V') { // virus
  //           w->fillRectangle(5 + 10 * j, 85 + 10 * i, 10, 10, 2); // red
  //         } else { // data
  //           w->fillRectangle(5 + 10 * j, 85 + 10 * i, 10, 10, 3); // green
  //         }
  //       } else { // needs if reveal
  //         w->fillRectangle(5 + 10 * j, 85 + 10 * i, 10, 10, 4); // black
  //       }
  //     } else { // firewall
  //       w->fillRectangle(5 + 10 * j, 85 + 10 * i, 10, 10, 8); // black
  //     }
  //   }
  // }

  ++turn;
}
