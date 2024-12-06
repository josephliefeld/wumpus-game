#include "bats.h"

#include <iostream>

using namespace std;

Bats::Bats() {

}

Bats::~Bats() {

}

char Bats::get_icon() {
    return 'B';
}

string Bats::get_percept() const {
    return "You hear wings flapping";
}

void Bats::encounter(Room& current_room, Game& current_game) const {
    cout << "You encounter a swarm of super bats! They confuse you in their anger!" << endl;
    cout << "The next 5 moves will be inverted!" << endl;
    current_game.gets_confused(5);
    current_game.is_confused(); 
}

//Bats Implementation
