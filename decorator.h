#ifndef DECORATOR_H
#define DECORATOR_H

#include "board.h"

class Decorator: public Board {
protected:
  Board* gB;
public:
  Decorator(Board* gameBoard);

  virtual ~Decorator();
};


/*
How important is serverport? We can probably implement this into blank
if we wanted to cause it's not going to change ever, but what kind of functionality
are we giving it?
*/
class Serverport: public Decorator {
  int position;
  int player;
public:
  Serverport(Board* next, int pos, int player);

  ~Serverport();

  char getTile(int pos) const override;

  bool isFirewall(int pos) const override;
};

class Firewall: public Decorator {
  int position;
  int player;
public:
  Firewall(Board* next, int pos, int player);

  ~Firewall();

  char getTile(int pos) const override;

  bool isFirewall(int pos) const override;
};

class DisplayLinks: public Decorator {
  Board* theBoard;
  public:

  DisplayLinks(Board* next);

  ~DisplayLinks();

  char getTile(int pos) const override;

  bool isFirewall(int pos) const override;
};

#endif