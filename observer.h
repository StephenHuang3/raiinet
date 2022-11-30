#ifndef _OBSERVER_H_
#define _OBSERVER_H_
#include "mapcontroller.h"
#include "subject.h"
#include "window.h"
#include "board.h"

class Subject;

class Observer {
 public:
  virtual void print(int player) = 0;
  virtual ~Observer() = default;
};

class textObserver: public Observer {
  Board *brd;
  public:
    textObserver(Board* brd);
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
