#include "subject.h"
#include "observer.h"

void Subject::attach(Observer *o){
    observers.emplace_back(o);
}

void Subject::detach(Observer *o){
    int z = observers.size();
    for (int i = 0; i < z; i++){
        if (observers[i]== o){
            observers.erase(observers.begin() + i);
        }
    }
}  

void Subject::notifyObservers(int player, int endGame){
    int z = observers.size();
    for (int i = 0; i < z; i++){
        observers[i]->print(player, endGame);
    }
}
