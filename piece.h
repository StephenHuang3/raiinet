#include <string>

class Piece {
  int player;
  std::string id;
  int boosted;
  int val;
public:
  Piece(int p, std::string id, int val);
  
  ~Piece();
  
  int move(char d);
};