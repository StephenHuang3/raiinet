#include "observer.h"
#include "window.h"
#include "mapcontroller.h"
#include "subject.h"

using namespace std;

textObserver::textObserver(Board* brd): brd{brd}{
    s->attach(this);
}

textObserver::~textObserver() {
  s->detach(this);
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
  s->detach(this);
  delete w;
}

graphicObserver::graphicObserver(Board* brd): brd{brd} {
  int width = 100 * 8 + 1;
  int height = 100 * 8 + 1;
  w = new Xwindow{width, height};
  this->s->attach(this);
}

void graphicObserver::print(int player) {
  if (player == 1){

  }else {
    
  }
}
