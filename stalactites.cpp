#include "stalactites.h"

#include <iostream>

using namespace std;

Stalactites::Stalactites() {
   
}

Stalactites::~Stalactites() {

}

char Stalactites::get_icon() {
    return 'S';
}

string Stalactites::get_percept() const {
    return "You hear water dripping.";
}

void Stalactites::encounter(Room& current_room, Game& current_game) const {
    current_game.display_game();
    int death_chance = rand() % 2;
    cout << "You've stumbled upon a room of stalactites! Watch Out!" << endl;
    if(death_chance == 0){
        current_game.stalactites_death();
    }else {
        cout << "Your quick reactions allow to narrowly avoid the stalactite, you may continue... " << endl;
    }
}


//Stalactites Implementation
