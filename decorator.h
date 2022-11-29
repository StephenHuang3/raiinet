#include "board.h"

class Decorator: public Board {
  Board* gameBoard;
public:
  Decorator(Board* gameBoard);
  virtual ~Decorator();
};

class Serverport: public Decorator {
public:
  Serverport(Board* next, int pos);

  ~Serverport();

  char getTile(int pos) const override;
};

class Firewall: public Decorator {
public:
  Firewall(Board* next, int pos);

  ~Firewall();

  char getTile(int pos) const override;
};

