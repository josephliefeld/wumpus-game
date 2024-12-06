#ifndef STALACTITES_H
#define STALACTITES_H 
#include "event.h"
#include "game.h"
#include <string>
using namespace std;
//Stalactites Interface

class Stalactites : public Event {

    protected:

    public: 
        Stalactites();
        ~Stalactites();
        virtual char get_icon() override;
        virtual string get_percept() const override;
        virtual void encounter(Room& current_room, Game& current_game) const override;
};

#endif
