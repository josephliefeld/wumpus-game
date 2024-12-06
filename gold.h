#ifndef GOLD_H
#define GOLD_H 
#include "event.h"
#include "game.h"
#include <string>
using namespace std;
//Gold Interface

class Gold : public Event {

    protected:

    public: 
        Gold();
        ~Gold();
        virtual char get_icon() override;
        virtual string get_percept() const override;
        virtual void encounter(Room& current_room, Game& current_game) const override;
};

#endif