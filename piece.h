#include <string>

class Piece {
  std::string id;
  int boosted;
public:
  Piece(std::string id);
  
  ~Piece();
  
  void move(char d);
};