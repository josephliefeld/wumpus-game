#include "room.h"

using namespace std;

Room::Room(){
    this -> e = nullptr;
    this -> player_here = false;
}

Room::~Room() {
    if(e != nullptr){
        delete e;
        e = nullptr;
    }
}

Room::Room(Event* type_event){
    this -> e = type_event;
}

/*char Room::get_room_icon() const {
    return this -> e -> get_icon();
}*/

bool Room::is_room_empty() const {
    return e == nullptr;
}

void Room::set_event(Event* event_call){
    if(this -> e != nullptr){
        delete e;
    }
    this -> e = event_call;
}

Event* Room::get_event() const {
    return e;
}

/*string Room::get_room_percept() {
    return this -> e -> get_percept();
}*/

bool Room::in_room() const {
    return player_here;
}

void Room::Set_Player(bool k) {
    this -> player_here = k;
}
//Room Implementation
