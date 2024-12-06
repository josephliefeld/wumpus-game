#ifndef EVENT_H
#define EVENT_H 

#include <string>
#include "player.h"
using namespace std;

//Event Interface
//Note: this must be an abstract class!

class Room;
class Game;

class Event {

public:
    virtual ~Event();
    virtual string get_percept() const = 0;
	virtual void encounter(Room& current_room, Game& current_game) const = 0; // EACH event needs to define their own encounter()!
	virtual char get_icon() = 0;
};
#endif