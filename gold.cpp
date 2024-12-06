#include "gold.h"

#include <iostream>

using namespace std;

Gold::Gold() {
    
}

Gold::~Gold() {

}

char Gold::get_icon() {
    return 'G';
}

string Gold::get_percept() const {
    return "You see a glimmer nearby."; 
}

void Gold::encounter(Room& current_room, Game& current_game) const {
    cout << "You've found the gold! However, you must now find your way back to the exit... " << endl;
    delete this;
    current_room.set_event(nullptr);
    current_game.found_gold();
}

//Gold Implementation
