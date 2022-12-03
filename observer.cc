#include "observer.h"
#include "mapcontroller.h"
#include "subject.h"
#include "window.h"

textObserver::textObserver(Mapcontroller* brd): brd{brd}{
    brd->attach(this);
}

textObserver::~textObserver() {
  brd->detach(this);
}

void textObserver::print(int player){
  if(player == 0) {
    std::cout << "========" << '\n';
    for( int i = 0; i < 8; ++i) {
      for( int j = 0; j < 8; ++j) {
        std::cout << brd->getTile(i+j*8);
      }
      std::cout << '\n';
    }
    std::cout << "========" << '\n';
  } else if (player == 1){
    std::cout << "Player 1:\nDownloaded: \nAbilities: "
    << "a: " << "b: " << "c: " << "d: " 
    << "\ne:" << "f: " << "g: " << "h: " << '\n';

  }else {
    std::cout << "Player 1:\nDownloaded: \nAbilities: "
    << "A: " << "B: " << "C: " << "D: " 
    << "\nE:" << "f: " << "g: " << "H: " << '\n';
  }
  
}
graphicObserver::~graphicObserver() {
  brd->detach(this);
  delete w;
}

graphicObserver::graphicObserver(Mapcontroller* brd): brd{brd} {
  int width = 100 * 8 + 1;
  int height = 100 * 8 + 1;
  w = new Xwindow{width, height};
  this->brd->attach(this);
}

void graphicObserver::print(int player) {
  if (player == 1){

  }else {
    
  }
}
