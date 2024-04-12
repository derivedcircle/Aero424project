#include <iostream>
#include <string>
#include <vector>
#include <regex>
#include "instructions.h"

using namespace std;

// overloaded function that personalizes instructions based on if the user has played the game before and if they want to speed up the instructions
void instructions()// runs if the user has not played the game before
{
	ifstream inFile("instructions.txt", ios::in); //opens the file that is declared to be "instructions.txt" 

	if (!inFile) //tests to see if the file opened sucessfully 
	{
		std::cerr << "Failed to open instructions instructions.txt" << std::endl;
		return;
	}

	std::string line; //creates a string holding the current line of text in the instructions file

	while (std::getline(inFile, line)) //repeats until no more lines are left
	{
	std:cout << line << std::endl; //reads each line in the ijnstructions file, stores it in the line string, and prints it to the command window
	}

	inFile.close(); // closes the file when finished with reading it 
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
		
		ifstream inFile("instructions.txt", ios::in); //opens the file that is declared to be "instructions.txt" 

		if (!inFile) //tests to see if the file opened sucessfully 
		{
			std::cerr << "Failed to open instructions instructions.txt" << std::endl;
			return;
		}

		std::string line; //creates a string holding the current line of text in the instructions file

		while (std::getline(inFile, line)) //repeats until no more lines are left
		{
		std:cout << line << std::endl; //reads each line in the ijnstructions file, stores it in the line string, and prints it to the command window
		}

		inFile.close(); // closes the file when finished with reading it 
	}
}