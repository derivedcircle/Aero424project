#include "userinterface.h"

using namespace std;


// function initializes everything for a new user
UserInterface::UserInterface(string name)
{
	username = name;
	hangarSpace = MAX_HANGAR_SPACE; // Can be adjusted - use in setting difficulty (may also be removed and added in plane class) (if so remove)
	moneySpent = 0.0;
	days = 0;
	hasPlaneCrashed = false;

}

// returns the current status for the user
ostream& operator<<(ostream& os, const UserInterface& obj)
{
	os << endl << "Current Status for user: " << obj.username << endl << "Day: " << obj.days << endl << "Money Spent: " << obj.moneySpent << endl <<
		"Hangar space remaining: " << obj.hangarSpace << " out of " << obj.MAX_HANGAR_SPACE << endl;
	// add something for which planes are currently here

	return os;

}


void UserInterface::hangarOperation()
{
	days++;// impliment later
}
