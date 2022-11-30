#include <map>

class Piece;

class Board {
  std::map<int, Piece*> board;
public:
  Board();

  ~Board();
  
  void start();
  
  void reset();
  
  virtual char getTile(int pos) const = 0;

  virtual bool isFirewall(int pos) const = 0;
};

