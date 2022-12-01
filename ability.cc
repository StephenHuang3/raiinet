#include "ability.h"
#include <string>

void Polarize::activate(Player* player, Piece* p, int pos){
    p->changeType();
}