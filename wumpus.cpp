#include "wumpus.h"

#include <iostream>

using namespace std;

Wumpus::Wumpus() {
    
}

Wumpus::~Wumpus() {

}

char Wumpus::get_icon() {
    return 'W';
}

string Wumpus::get_percept() const {
    return "You smell a terrible stench.";
}

void Wumpus::encounter(Room& current_room, Game& current_game) const {
    current_game.slain_by_wumpus();
}



//Wumpus Implementation
