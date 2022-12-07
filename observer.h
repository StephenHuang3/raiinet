#ifndef _OBSERVER_H_
#define _OBSERVER_H_

#include "mapcontroller.h"
#include "subject.h"
#include "board.h"
#include "player.h"
#include "window.h"

class Observer {
public:
  virtual void print(int player) = 0;
  virtual ~Observer() = default;
};

class textObserver: public Observer {
  Mapcontroller *theMap;
  public:
    textObserver(Mapcontroller* theMap);
    void print(int player, int endGame) override;
    ~textObserver() override;
};

class graphicObserver: public Observer {
  Mapcontroller* theMap;
  Xwindow* w;
  int turn = 1;
  public:
    int brdX = 204;
    int brdY = 187;
    // void incrementTurn();
    // int getTurn();
    graphicObserver(Mapcontroller* theMap);
    ~graphicObserver() override;
    void print(int player, int endGame) override;
};

#endif
