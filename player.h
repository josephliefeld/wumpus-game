#ifndef PLAYER_H
#define PLAYER_H

struct player {
    bool is_alive = true;
    bool has_gold = false;
    bool win = false;
    int bat_spell = 0;
    int x_start;
    int y_start;
    int x_loc;
    int y_loc;
};

#endif