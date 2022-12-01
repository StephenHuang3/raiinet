#ifndef PIECE_H
#define PIECE_H

#include <string>

/* 
Question: Do we want to make piece a decorator? 
Pros: makes implementation of printing out the board easier - only need getTitle
Cons: may cause move() functionality to be more complicated?
      idk I haven't really thought this through
*/
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

#endif
