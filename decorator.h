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

class Serverport: public Decorator {
  int position;
  int player;
public:
  Serverport(Board* next, int pos, int player);

  ~Serverport();

  char getTile(int pos) const override;

  int isFirewall(int pos) const override;
};

class FirewallTile: public Decorator {
  int position;
  int player;
public:
  FirewallTile(Board* next, int pos, int player);

  ~FirewallTile();

  char getTile(int pos) const override;

  int isFirewall(int pos) const override;
};

class DisplayLinks: public Decorator {
  public:

  DisplayLinks(Board* next);

  ~DisplayLinks();

  char getTile(int pos) const override;

  int isFirewall(int pos) const override;
};

#endif
