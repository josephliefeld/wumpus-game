#ifndef BATS_H
#define BATS_H 
#include "event.h"
#include "game.h"
#include <string>
using namespace std;
//Bats Interface

class Bats : public Event {

    protected:

    public: 
        Bats();
        ~Bats();
        virtual char get_icon() override;
        string get_percept() const override;
        void encounter(Room& current_room, Game& current_game) const override;
};

#endif