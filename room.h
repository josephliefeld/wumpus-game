#ifndef ROOM_H
#define ROOM_H 

#include <string>
#include "event.h"

using namespace std;

//Room Interface
//Note: Each room may be empty or has an event (bat, gold, pit, or wumpus);
//		Use event polymorphically

class Room
{
private: 
	Event* e;
    bool player_here;
public:
	Room();
    Room(Event* type_event);
    ~Room();
    void Set_Player(bool k);
    bool in_room() const;
    void set_event(Event* event_call);
    Event* get_event() const;
    void print_room() const;
    /*string get_room_percept();
    void set_room_icon() const;
    char get_room_icon() const;*/
    bool is_room_empty() const;
};

#endif