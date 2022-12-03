#ifndef _OBSERVER_H_
#define _OBSERVER_H_

#include "mapcontroller.h"
#include "subject.h"
#include "board.h"
#include "player.h"

using namespace std;

class Observer {
public:
  virtual void print(int player) = 0;
  virtual ~Observer() = default;
};

class textObserver: public Observer {
  Mapcontroller *theMap;
  public:
    textObserver(Mapcontroller* theMap);
    void print(int player) override;
    ~textObserver() override;
};

class graphicObserver: public Observer {
  Mapcontroller* brd;
  Xwindow* w;
  public:
    graphicObserver(Mapcontroller* brd);
    ~graphicObserver() override;
    void print(int player) override;
};

#endif
