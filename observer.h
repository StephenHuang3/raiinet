#ifndef _OBSERVER_H_
#define _OBSERVER_H_

#include "mapcontroller.h"
#include "subject.h"
#include "board.h"

class Subject;

class Observer {
public:
  virtual void print(int player) = 0;
  virtual ~Observer() = default;
};

class textObserver: public Observer {
  Mapcontroller *brd;
  public:
    textObserver(Mapcontroller* brd);
    void print(int player) override;
    ~textObserver() override;
};

class graphicObserver: public Observer {
  Board* brd;
  Xwindow* w;
  public:
    graphicObserver(Board* brd);
    ~graphicObserver() override;
    void print(int player) override;
};

#endif
