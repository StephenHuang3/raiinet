#ifndef BLANK_H
#define BLANK_H

#include "board.h"

class Blank: public Board {
public:
  Blank();

  ~Blank();
  
  char getTile(int pos) const override;

  int isFirewall(int pos) const override;  
};

#endif
