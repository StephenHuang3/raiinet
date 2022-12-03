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
  char id;
  char type;
  int boosted;
  int val;
public:
  Piece::Piece(int p, char id, char type, int val);
  
  ~Piece();
  
  int move(char d);

  char getId() const;

  int getPlayer() const;

  char getType() const;

  void changeType();

  void addVal();
  void boost();

  int getVal();
};

#endif
