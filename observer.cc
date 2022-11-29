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
  if (player == 1){

  }else {

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
