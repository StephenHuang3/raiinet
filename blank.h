#include "board.h"

class Blank: public Board {
public:
  Blank();

  ~Blank();
  
  char getTile(int pos) const override;
};