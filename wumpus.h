#ifndef WUMPUS_H
#define WUMPUS_H 
#include "event.h"
#include "game.h"
#include <string>
using namespace std;
//Wumpus Interface

class Wumpus : public Event {

    protected:

    public: 
        Wumpus();
        ~Wumpus();
        virtual char get_icon() override;
        virtual string get_percept() const override;
        virtual void encounter(Room& current_room, Game& current_game) const override;
};


#endif