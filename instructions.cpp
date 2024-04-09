#include <iostream>
#include <string>
#include <vector>
#include <regex>
#include "instructions.h"

using namespace std;

// overloaded function that personalizes instructions based on if the user has played the game before and if they want to speed up the instructions
void instructions()// runs if the user has not played the game before
{
	cout << "TO DO" << endl;
	// to impliment
	// add full instructions set here
}

void instructions(bool expidite) // runs if the user has played the game before
{
	if (expidite) // this skips the instructions for the user if desired
	{
		cout << "Sounds good, welcome back" << endl;
	}
	else // this runs through the instructions if the user has played the game before but does not remember how to play
	{
		cout << "Welcome back to the game, lets get you back up to speed" << endl;
		
		cout << "TO DO" << endl;
		// to impliment
		// add full instructions set here
	}
}