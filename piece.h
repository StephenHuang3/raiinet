#ifndef PIECE_H
#define PIECE_H

#include <string>
using namespace std;

/* 
Question: Do we want to make piece a decorator? 
Pros: makes implementation of printing out the board easier - only need getTitle
Cons: may cause move() functionality to be more complicated?
      idk I haven't really thought this through
*/
class Piece {
  int player;
  char id;
  string type;
  int boosted = 0;
  int val;
  bool downloaded = false;
public:
  Piece::Piece(int p, char id, string type, int val);
  
  ~Piece();
  
  int move(char d);

  char getId() const;

  int getPlayer() const;

  string getType() const;
  void changeType();

  void addVal();
  void boost();

  int getVal();
};

#endif
