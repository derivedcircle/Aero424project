#include "userinterface.h"
#include <array>
#include <thread>
#include "randomnumbergenerators.h"
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
		"Hangar space remaining: " << obj.hangarSpace << " out of " << obj.MAX_HANGAR_SPACE << endl << endl;
	for (auto it = obj.planesInHangar.begin(); it != obj.planesInHangar.end(); it++)
	{
		os << "Plane " << it->first << " has " << it->second << " days remaining for its repair" << endl;
	}

	return os;

}


void UserInterface::hangarOperation()
{
	days++;// impliment later
	for (auto it = planesInHangar.begin(); it != planesInHangar.end(); it++)
	{
		it->second--;
		if (it->second == 0)
		{
			//what happens when the plane completes it maintanance (it leaves and check if it will crash after
		}

	}
}

void UserInterface::newAircraftArrivals()
{
	array<array<int, 2>, 3> aircraftGenerationMatrix;
	/*
	This is a 2x3 matrix and is set up like this:
	Aircraft 1 type (0-7) | Aircraft 1 problem (0-1)
	------------------------------------------------
	Aircraft 2 type (0-7) | Aircraft 2 problem (0-1)
	------------------------------------------------
	Aircraft 3 type (0-7) | Aircraft 3 problem (0-1)

	We are then using a randomizer to populate the matrix with values
	*/
	thread t1 = thread(randOf8, ref(aircraftGenerationMatrix), 0);
	thread t2 = thread(randOf2, ref(aircraftGenerationMatrix), 0);
	thread t3 = thread(randOf8, ref(aircraftGenerationMatrix), 1);
	thread t4 = thread(randOf2, ref(aircraftGenerationMatrix), 1);
	thread t5 = thread(randOf8, ref(aircraftGenerationMatrix), 2);
	thread t6 = thread(randOf2, ref(aircraftGenerationMatrix), 2);

	t1.join();
	t2.join();
	t3.join();
	t4.join();
	t5.join();
	t6.join();

	for (int i = 0; i < 3; ++i) {
		for (int j = 0; j < 2; ++j) {
			cout << aircraftGenerationMatrix[i][j] << " ";
		}
		cout << endl;
	}
}