#include <iostream>
#include <string>
#include <vector>
#include <regex>
#include "initializer.h"
#include "instructions.h"

using namespace std;


string initFun()
{
	// brief greeting/introduction (feel free to change name to whatever)
	cout << "Hello and welcome to Aircraft Maintanance Tycoon" << endl;
	cout << "To win, you need to survive the longest without having a crash" << endl << endl;
	
	// logic code for deciding which instruction set the user should be served
	bool hasPlayed;
	string playGameCheck;
	bool skipInstr;
	string skipInstrCheck;
	
	// the regex checks for yes/no or y/n with any capitalization
	while (!regex_match(playGameCheck, regex("^[y|Y][e|E][s|S]$|^[n|N][o|O]$|^[n|N]$|^[y|Y]$")))
	{
		// forces user to input a valid input for command before proceding
		cout << "Have you played this game before? (Answer with a yes/no or y/n) ";
		getline(cin, playGameCheck);
	}

	// saves if the user has played the game before
	hasPlayed = regex_match(playGameCheck, regex("^[y|Y][e|E][s|S]$|^[y|Y]$"));
	
	if (hasPlayed)
	{
		
		// the regex checks for yes/no or y/n with any capitalization
		while (!regex_match(skipInstrCheck, regex("^[y|Y][e|E][s|S]$|^[n|N][o|O]$|^[n|N]$|^[y|Y]$")))
		{
			// forces user to input a valid input for command before proceding
			cout << "Would you like to skip the directions for the game? (Answer with a yes/no or y/n) ";
			getline(cin, skipInstrCheck);
		}
		// saves if the user wants to skip the instructions or not
		skipInstr = regex_match(skipInstrCheck, regex("^[y|Y][e|E][s|S]$|^[y|Y]$"));
		instructions(skipInstr);

	}
	else
	{
		// displays the instructions to the game
		instructions();
	}
	
	
	string name; // string to hold the user's entered name
	cout << "Now lets get started" << endl;
	// getting the user's name (regex checks for the general structure of a first middle(optional) last name or just a first name if inputted
	while (!regex_match(name, regex("^([a-zA-Z]).*( [a-zA-Z]+)$|^([a-zA-Z]+)$")))
	{
		
		cout << "What is your full name? ";
		getline(cin, name);
		
	}
	
	smatch displayNameTokens;// search match all tokens to generate the display name (which will be either first initial last name or just first name)
	regex_search(name, displayNameTokens, regex("^([a-zA-Z]).*( [a-zA-Z]+)$|^([a-zA-Z]+)$"));

	string displayName;
	uint8_t count = 0;// this is needed to skip the first input of the smatch and using an 8bit int to save a bit on memory
	for (auto x : displayNameTokens)
	{
		if (count == 0)
			;// used to ignore the first token saved in the smatch
		else {
			displayName.append(x); // adds all of the other tokens from the smatch to 
			// generate the display name (which will be either first initial last name or just first name)
		}
		
		count++;
	}

	return displayName; // returns the display name for the user in the described format
}