#include <iostream>
#include <string>
#include <vector>
#include <regex>
//all standard libraries used
#include "plane.h"
#include "initializer.h"
#include "instructions.h"
#include "userinterface.h"
// all header files to include
// hello :)

using namespace std;
// setting default namespace as standard for convenience

// high score global varible to keep track of the highest score earned in game
int HIGH_SCORE_GV = 0;

int main()
{
	bool playAgain;
	do// loop to play the game again
	{
		UserInterface user1(initFun());
		while (!user1.hasPlaneCrashed)
		{
			cout << user1 << endl;
			user1.newAircraftArrivals();
			user1.hangarOperation();
		}
		// game over code

		cout << "A plane crashed and as a result, you were fired" << endl;
		if (user1.days > HIGH_SCORE_GV)
		{
			HIGH_SCORE_GV = user1.days;
			cout << "You have just acheved the high score! Congratulations!" << endl;
		}
		cout << "Here are the names of those who have played before you" << endl;
		for (auto& names : user1.userHistory)
		{
			cout << names << endl;
		}
		string playGameAgainCheck;
		
		//clearing input buffer to avoid skipping getline
		cin.ignore(numeric_limits<streamsize>::max(), '\n');

		// the regex checks for yes/no or y/n with any capitalization
		while (!regex_match(playGameAgainCheck, regex("^[y|Y][e|E][s|S]$|^[n|N][o|O]$|^[n|N]$|^[y|Y]$")))
		{
			// forces user to input a valid input for command before proceding
			cout << "Would you like to play again? (Answer with a yes/no or y/n) ";
			getline(cin, playGameAgainCheck);
		}

		// saves if the user wants to play the game again
		playAgain = regex_match(playGameAgainCheck, regex("^[y|Y][e|E][s|S]$|^[y|Y]$"));
	} while (playAgain);
	return 0;
}