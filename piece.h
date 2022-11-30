#include <string>

class Piece {
  int player;
  std::string id;
  int boosted;
public:
  Piece(int p, std::string id);
  
  ~Piece();
  
  void move(char d);
};