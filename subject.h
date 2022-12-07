#ifndef SUBJECT_H
#define SUBJECT_H
#include <vector>

class Observer;

class Subject {
  std::vector<Observer*> observers;
 public:
  void attach(Observer *o);
  void detach(Observer *o);
  void notifyObservers(int player, int endResult);
  virtual char getTile(int pos) const = 0;
  virtual ~Subject() = default;
};

#endif
