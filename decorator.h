#include "board.h"

class Decorator: public Board {
protected:
  Board* gB;
public:
  Decorator(Board* gameBoard);
  virtual ~Decorator();
};

class Serverport: public Decorator {
  int pos;
public:
  Serverport(Board* next, int pos);

  ~Serverport();

  char getTile(int pos) const override;
};

class Firewall: public Decorator {
  int pos;
public:
  Firewall(Board* next, int pos);

  ~Firewall();

  char getTile(int pos) const override;
};

