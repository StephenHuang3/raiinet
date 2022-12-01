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
  int pos;
public:
  Serverport(Board* next, int pos);

  ~Serverport();

  char getTile(int pos) const override;

  bool isFirewall(int pos) const override;
};

class Firewall: public Decorator {
  int pos;
public:
  Firewall(Board* next, int pos);

  ~Firewall();

  char getTile(int pos) const override;

  bool isFirewall(int pos) const override;
};

