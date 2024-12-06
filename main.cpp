#include <iostream>
#include <cstdlib>
#include <ctime>
#include "game.h"

using namespace std;

int get_length(){
	bool good_input = true;
	int l;
	do {
		cout << "Please insert the length (between 4-50): " << endl;
		cin >> l;
		if(l >= 4 && 50 >= l) {
			good_input = false;
		}else {
			cout << "Error! Please input a valid integer." << endl;
		}
	} while(good_input == true);
	return l;
}

int get_width(){
	bool good_input = true;
	int w;
	do {
		cout << "Please insert the length (between 4-50): " << endl;
		cin >> w;
		if(w >= 4 && 50 >= w) {
			good_input = false;
		}else {
			cout << "Error! Please input a valid integer." << endl;
		}
	} while(good_input == true);
	return w;
}

bool get_debug() {
	bool check = true;
	char choice;

	cout << "Do you want to play in debug mode or normal mode?" << endl;
	do {
		cout << "Enter a 'D' for debug mode or 'N' for normal mode: " << endl;
		cin >> choice;
		if(choice == 'D'){
			check = false;
			return true;
		}else if(choice == 'N'){
			check = false;
			return false;
		}else {
			cout << "Error! Please enter a valid input." << endl;
		}
	} while(check);

	return false;
}

int main()
{
	//set the random seed
	srand(time(NULL));
	
	int wid, len;
	bool debug = false;
	
	Game g;
	//get two inputs: size of the cave(wid and len)
	len = get_length();
	wid = get_width();

	//get the 3rd input --> debug mode or not
	debug = get_debug();

	//Play game
	g.play_game(wid, len, debug);


	return 0;
}