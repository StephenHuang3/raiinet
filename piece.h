#include <string>

class Piece {
  int player;
  std::string id;
  int boosted;
public:
  Piece(int p, std::string id);
  
  ~Piece();
  
  int move(char d);
};