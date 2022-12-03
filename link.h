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
  int boosted;
  int val;
  bool downloaded = false;
public:
  Link::Link(int p, char id, char type, int val);
  
  ~Link();
  
  int move(char d);

  char getId() const;

  int getPlayer() const;

  char getType() const;

  void changeType();

  void addVal();
  void boost();

  int getVal();

  void download();
};

#endif
