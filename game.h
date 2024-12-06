#ifndef GAME_H
#define GAME_H 

#include <vector>
#include <iostream> 
#include "room.h"

using namespace std;

//Game interface 
class Game
{
private:
	
	//declare a 2D vector of Room objects:
	vector < vector < Room> > grid;	
	//other member variables:
	int length; 			//length of the board
	int width;  			//width of the board
	int num_arrows; 		//keep track of number of errors remaining
	bool debug_view;		//debug mode or not
	int player_x; 			// player's current x position (column)
	int player_y;			// player's current y position (row)
	int begin_x;			// player's starting x position (column)
	int begin_y;			// player's starting y position (row)
	int num_confuse;		// number of turns the player is confused for
	bool is_player_confused; // is the player confused
	bool is_wumpus_dead; 	// tracks the status of the wumpus 
	bool player_has_gold; 	// tracks if the player has the gold
	bool game_over;			// if true, end game
	//feel free to add more variables...

public:

	//suggested functions:
	Game();
	~Game();
	
	vector<vector<Room>> generate_grid(int length, int width);
	void set_up(int, int);

	void display_game() const;

	bool check_win() const;

	char get_dir();
	void wumpus_move();
	void fire_arrow();

	void move_up();
	void move_down();
	void move_left();
	void move_right();
	void move(char);

	char get_input();

	void play_game(int, int, bool);
	void display_percepts() const;
	void handle_encounter();

	void add_bats();
	void add_wumpus();
	void add_gold();
	void add_stalactites();

	void gets_confused(int num_turns);
	bool is_confused();

	bool wumpus_slain();
	void slain_by_wumpus();

	void stalactites_death();

	bool found_gold();
	//feel free (and you will need) to add more functions...




};
#endif