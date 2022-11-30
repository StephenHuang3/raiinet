#include <string>

class Piece {
  int player;
  std::string id;
  int boosted;
  int val;
public:
  Piece(int p, std::string id);
  
  ~Piece();
  
  int move(char d);

  std::string getId() const;

  int getPlayer() const;
};