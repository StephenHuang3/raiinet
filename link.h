#ifndef LINK_H
#define LINK_H

#include <string>

/* 
Question: Do we want to make link a decorator? 
Pros: makes implementation of printing out the board easier - only need getTitle
Cons: may cause move() functionality to be more complicated?
      idk I haven't really thought this through
*/
class Link {
  int player;
  char id;
  char type;
  int pos;
  int moveAmount = 1;
  int val;
  bool downloaded = false;
  bool revealed = false;
public:
  Link(int p, int pos, char id, char type, int val);
  
  ~Link();
  
  char getId() const;

  int getPos() const;

  int getPlayer() const;
  
  char getType() const;
  
  int getMoveAmount() const;
  
  bool getDownloaded() const;

  void changeType();

  void changePos(int newPos);

  void addVal();
  
  void boost();

  int getVal() const;

  void toggleDownloaded();

  void reveal();
};

#endif
