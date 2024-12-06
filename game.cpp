#include "game.h"
#include "gold.h"
#include "stalactites.h"
#include "bats.h"
#include "wumpus.h"

#include <iostream>
#include <vector>
#include <ctime>
#include <cstdlib>

using namespace std;

//Game Implementation

Game::Game(){
	this -> length;
	this -> width;
	this -> num_arrows = 3;
	this -> debug_view = true;
	this -> player_y = 0;
	this -> player_x = 0;
	this -> begin_y = 0;
	this -> begin_x= 0;
	this -> length = 0;
	this -> num_confuse = 0;
	this -> is_player_confused = false;
	this -> is_wumpus_dead = false;
	this -> player_has_gold = false;
	this -> game_over = false;
}

Game::~Game(){
	/*for(int i = 0; i < length; ++i){
		for(int j = 0; j <width; ++j){
			delete grid[i][j].get_event();
			grid[i][j].set_event(nullptr);
		}
	}
	grid.clear();*/
}

/*void Game::add_bats(){
	int x = 0;
	int y = 0;
	int num_bats = 0;
	do {
		x = rand() % this -> width;
		y = rand() % this -> length;
		if(grid[y][x].get_room_icon() == ' '){
			grid[y][x].set_event(new Bats);
			cout << num_bats;
			num_bats++;
		}else{
			x = rand() % this -> width;
			y = rand() % this -> length;
		}
	}while(num_bats < 2);
}

void Game::add_wumpus(){
	int x = 0;
	int y = 0;
	int num_wumpus = 0;
	do {
		x = rand() % this -> width;
		y = rand() % this -> length;
		if(grid[y][x].get_room_icon() == ' '){
			grid[y][x].set_event(new Wumpus());
			cout << num_wumpus;
			num_wumpus++;
		}else{
			x = rand() % this -> width;
			y = rand() % this -> length;
		}
	}while(num_wumpus < 1);
}

void Game::add_gold(){
	int x = 0;
	int y = 0;
	int num_gold = 0;
	do {
		x = rand() % this -> width;
		y = rand() % this -> length;
		if(grid[y][x].get_room_icon() == ' '){
			grid[y][x].set_event(new Gold);
			cout << num_gold;
			num_gold++;
		}else{
			x = rand() % this -> width;
			y = rand() % this -> length;
		}
	}while(num_gold < 1);
}

void Game::add_stalactites(){
	int x = 0;
	int y = 0;
	int num_stalactites = 0;
	do {
		x = rand() % this -> width;
		y = rand() % this -> length;
		if(grid[y][x].get_room_icon() == ' '){
			grid[y][x].set_event(new Stalactites);
			cout << num_stalactites;
			num_stalactites++;
		}else{
			x = rand() % this -> width;
			y = rand() % this -> length;
		}
	}while(num_stalactites < 2);
}*/

void Game::set_up(int l, int w){
	this->length = l;
	this->width = w;

	vector<vector<Room>> tmp(l, vector<Room>(w));
	this->grid = tmp;

	this->num_arrows = 3; 	
	/*add_bats();
	add_wumpus();
	add_gold();
	add_stalactites();*/

	int num_bats = 0;
	int num_stalactites = 0;
	int num_gold = 0;
	int num_wumpus = 0;
	while(num_bats < 2 || num_stalactites < 2 || num_gold < 1 || num_wumpus < 1){
		int y = rand() % length;
		int x = rand() % width;
		if(this->grid[y][x].is_room_empty()) {
			if(num_bats < 2) {
				this->grid[y][x].set_event(new Bats());
				num_bats++;
			}else if(num_stalactites < 2) {
				this->grid[y][x].set_event(new Stalactites());
				num_stalactites++;
			}else if(num_wumpus < 1) {
				this->grid[y][x].set_event(new Wumpus());
				num_wumpus++;
			}else if(num_gold < 1) {
				this->grid[y][x].set_event(new Gold());
				num_gold++;
			}
		}
	}

	do {
		player_x = rand() % width;
		player_y = rand() % length;
	} while(!(grid[player_y][player_x].is_room_empty()));

	begin_x = player_x;
	begin_y = player_y;
	grid[player_y][player_x].Set_Player(true);
}

//Note: you need to modify this function
void Game::display_game() const{
	cout << endl << endl;
	cout << "Arrows remaining: " << this->num_arrows << endl;
	
	string line = "";
	for (int i = 0; i < this->width; ++i)
		line += "-----";

	for (int i = 0; i < this->length; ++i)
	{
		cout << line << endl;
		for (int j = 0; j < this->width; ++j) {
			if(grid[i][j].in_room()) {
				cout << "*";
			} else {
				cout << " ";
			}
			
			if(debug_view) {
				if(i == begin_y && j == begin_x){
					cout << "E";
				}
			}

			if(grid[i][j].get_event()) {
				if(debug_view) {
					cout << grid[i][j].get_event() -> get_icon();
				}else {
					cout << " ";
				}
				cout << "  ||";
			}
		}
		cout << endl;
	}
	cout << line << endl;
}

bool Game::check_win() const{
	if(player_has_gold == true && player_y == begin_y && player_x == begin_x) {
		display_game();
		cout << endl << "You escaped with the gold! You win!" << endl;
		return true;
	}else if(is_wumpus_dead == true) {
		display_game();
		cout << "Your arrow finds the heart of the Wumpus! You win!" << endl;
		return true;
	}else {
		return false;
	}
}

void Game::move_up() {
	if(num_confuse > 0 && is_player_confused == true){
		if(player_y < (length - 1)){
			grid[player_y][player_x].Set_Player(false);
			player_y++;
			grid[player_y][player_x].Set_Player(true);
			num_confuse--;
		}else {
			cout << "Cannot move down, You're at the bottom border." << endl;
		}
	}else {
		if(player_y > 0) {
			grid[player_y][player_x].Set_Player(false);
			player_y--;
			grid[player_y][player_x].Set_Player(true);
		}else {
			cout << "Cannot move up, You're at the top boarder." << endl;
		}
	}
}

void Game::move_down() {
	if(num_confuse > 0 && is_player_confused == true){
		if(player_y > 0){
			grid[player_y][player_x].Set_Player(false);
			player_y--;
			grid[player_y][player_x].Set_Player(true);
			num_confuse--;
		}else {
			cout << "Cannot move down, You're at the top border." << endl;
		}
	}else {
		if(player_y < (length - 1)) {
			grid[player_y][player_x].Set_Player(false);
			player_y++;
			grid[player_y][player_x].Set_Player(true);
		}else {
			cout << "Cannot move up, You're at the bottom boarder." << endl;
		}
	}
}

void Game::move_left() {
	if(num_confuse > 0 && is_player_confused == true){
		if(player_x < (width - 1)){
			grid[player_y][player_x].Set_Player(false);
			player_x++;
			grid[player_y][player_x].Set_Player(true);
			num_confuse--;
		}else {
			cout << "Cannot move down, You're at the right border." << endl;
		}
	}else {
		if(player_x > 0) {
			grid[player_y][player_x].Set_Player(false);
			player_x--;
			grid[player_y][player_x].Set_Player(true);
		}else {
			cout << "Cannot move up, You're at the left boarder." << endl;
		}
	}
}

void Game::move_right() {
	if(num_confuse > 0 && is_player_confused == true){
		if(player_x > 0){
			grid[player_y][player_x].Set_Player(false);
			player_x--;
			grid[player_y][player_x].Set_Player(true);
			num_confuse--;
		}else {
			cout << "Cannot move down, You're at the left border." << endl;
		}
	}else {
		if(player_x < (width - 1)) {
			grid[player_y][player_x].Set_Player(false);
			player_x++;
			grid[player_y][player_x].Set_Player(true);
		}else {
			cout << "Cannot move up, You're at the right boarder." << endl;
		}
	}
}

char Game::get_dir(){
	char dir;
	bool good_input = false;

	cout << "Fire an arrow...." << endl;
	cout << "W-up" << endl;
	cout << "A-left" << endl;
	cout << "S-down" << endl;
	cout << "D-right" << endl;
	
	do {
		cout << "Enter direction: " << endl;
		cin >> dir;
		cin.ignore(256, '\n');

		if(dir == 'W' || dir == 'A' || dir == 'S' || dir == 'D'){
			good_input = true;
		}else {
			cout << "Error! Please enter a valid input." << endl;
		}
	} while(good_input == false);
	return dir;
}

void Game::wumpus_move(){
	//after a missed arrow, 75% chance that the wumpus is moved to a different room
	int move_chance = rand() % 4;
	if(move_chance != 0) {
		int new_wumpus_row, new_wumpus_col;
		do {
			new_wumpus_row = rand() % length;
			new_wumpus_col = rand() % width;
		} while(grid[new_wumpus_row][new_wumpus_col].get_event() != nullptr 
		|| (new_wumpus_row == begin_y && new_wumpus_col == begin_x) 
		|| (new_wumpus_row == player_y && new_wumpus_col == player_x));
		int c_row = -1;
		int c_col = -1;
		for(int i = 0; i < length; i++){
			for(int j = 0; i < width; j++){
				if(grid[i][j].get_event() != nullptr && grid[i][j].get_event() -> get_icon() == 'W'){
					c_row = i;
					c_col = j;
					break;
				}
			}
			if(c_row != -1) {
				break;
			}
		}
		if(c_row != -1){
			delete grid[c_row][c_col].get_event();
			grid[c_row][c_col].set_event(nullptr);
			grid[new_wumpus_row][new_wumpus_col].set_event(new Wumpus());
			cout << "The Wumpus heard your arrow and has moved to a new location... " << endl;
		}
	}
}

void Game::fire_arrow(){
	char dir = get_dir();
	int arrow_row_dir = 0, arrow_col_dir = 0;
	switch(dir) {
		case 'W':
			arrow_row_dir = -1;
			break;
		case 'A':
			arrow_col_dir = -1;
			break;
		case 'S': 
			arrow_row_dir = 1;
			break;
		case 'D':
			arrow_col_dir = 1;
			break;
		default:
			cout << "Invalid direction given. No arrow fired." << endl;
			return;
	}
	int arrow_y = player_y;
	int arrow_x = player_x;
	for(int i = 0; i < 3; ++i) {
		arrow_y += arrow_row_dir;
		arrow_x += arrow_col_dir;
		if(arrow_y < 0 || arrow_y >= length || arrow_x < 0 || arrow_x >= width){
			cout << "Your arrow hit a wall! The Wumpus remains unslain... " << endl;
			wumpus_move();
			num_arrows--;
			return;
		}
		if(grid[arrow_y][arrow_x].get_event() != nullptr && grid[arrow_y][arrow_x].get_event() -> get_icon() == 'W'){
			wumpus_slain();
			num_arrows--; 
			return;
		}
	}
	num_arrows--;
	cout << "Your arrow missed! The Wumpus remains unslain... " << endl;
	wumpus_move();
}

void Game::move(char c) {
	// Handle player's action: move or fire an arrow
	if (c == 'F'){
		if(num_arrows <= 0) {
			cout << "You are out of arrows." << endl;
			return;
		}else {
			Game::fire_arrow();
			return;
		}
	}
	switch(c){
		case 'W':
			Game::move_up();
			break;
		case 'A':
			Game::move_left();
			break;
		case 'S':
			Game::move_down();
			break;
		case 'D':
			Game::move_right();
			break;
	}
}

char Game::get_input(){
	char c;
	bool good_input = false;

	cout << endl << endl << "Player move..." << endl << endl;
	cout << "W-up" << endl;
	cout << "A-left" << endl;
	cout << "S-down" << endl;
	cout << "D-right" << endl;
	cout << "F-fire an arrow" << endl;

	do {
		cout << "Enter input (uppercase only): " << endl;
		cin >> c;
		if(c == 'W' || c == 'A' || c == 'S' || c == 'D' || c == 'F'){
			good_input = true;
		}else {
			cout << "Error! Please enter a valid input." << endl; 
		}
	} while(good_input = false);
	
	cin.ignore(256, '\n');

	return c;
}

//Note: you need to modify this function
void Game::play_game(int w, int l, bool d){
	Game::set_up(w, l);
	this->debug_view = d;
	char input, arrow_input;
	while (Game::check_win() == false && game_over == false){
		//print game board
		Game::display_game();

		//display percerts around player's location
		//Your code here:
		display_percepts();

		//Player move...
		//1. get input
		input = Game::get_input();

		//2. move player
		Game::move(input);

		//3. may or may not encounter events
		//Your code here:
		Game::handle_encounter();
	}
	return;
}

void Game::display_percepts() const{
	int player_row = player_y;
	int player_col = player_x;
	for(int i = -1; i <= 1; ++i){
		for(int j = -1; j <= 1; ++j){
			if((i == 0 && j == 0) || (i != 0 && j != 0)){
				continue;
			}
			int col = player_col + j;
			int row = player_row + i;
			if(row >= 0 && row < length && col >= 0 && col < width){
				if(grid[row][col].get_event() != nullptr) {
					cout << grid[row][col].get_event() -> get_percept() << endl;
				}
			}
		}
	}
}

void Game::handle_encounter() {
	Room& current_room = grid[player_y][player_x];
	Event* event_in_room = current_room.get_event();
	if(event_in_room != nullptr) {
		event_in_room -> encounter(current_room, *this);
	}
}

void Game::gets_confused(int num_turns){
	num_confuse = num_turns;
}

bool Game::is_confused() {
	is_player_confused = true;
	return is_player_confused;
}

bool Game::wumpus_slain() {
	is_wumpus_dead = true;
	return is_wumpus_dead;
}

void Game::slain_by_wumpus() {
	display_game();
	cout << "In a stroke of bad luck, you find yourself in the same room as the Wumpus... " << endl;
	cout << "Angered for waking them, the Wumpus effortlessly rips you to shreds. Game over... " << endl;
	game_over = true;
}

void Game::stalactites_death() {
	cout << "You were too slow and got impaled by falling stalactites, game over... " << endl;
	game_over = true;
}

bool Game::found_gold() {
	player_has_gold = true;
	return player_has_gold;	
}