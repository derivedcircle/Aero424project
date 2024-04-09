#include <iostream>
#include <string>
#include <vector>
#include <regex>
#include "initializer.h"
#include "instructions.h"

using namespace std;


vector<char> initFun()
{
	// brief greeting/introduction (feel free to change name to whatever)
	cout << "Hello and welcome to Aircraft Maintanance Tycoon" << endl;
	cout << "To win, you need to survive the longest without having a crash" << endl << endl;
	
	// logic code for deciding which instruction set the user should be served
	bool hasPlayed;
	string playGameCheck;
	bool skipInstr;
	string skipInstrCheck;

	cout << "Have you played this game before? (Answer with a yes/no or y/n" << endl;
	getline(cin, playGameCheck);


	string name;

	// getting the user's name
	cout << "To start, what is your name? ";
	getline(cin, name);



}