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
  string id;
  string type;
  int boosted;
  int val;
public:
  Piece(int p, string id, string type);
  
  ~Piece();
  
  int move(char d);

  string getId() const;

  int getPlayer() const;

  string getType() const;
  void changeType();
};

#endif
