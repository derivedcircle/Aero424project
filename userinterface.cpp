#include "userinterface.h"
#include <array>
#include <thread>
#include <vector>
#include <algorithm>
#include "randomnumbergenerators.h"
#include "plane.h"
#include "A220.h"
#include "A320.h"
#include "A330.h"
#include "A350.h"
#include "B737.h"
#include "B767.h"
#include "B777.h"
#include "B787.h"
using namespace std;

vector<string> UserInterface::userHistory = {};// needed to initialize static varible

// function initializes everything for a new user
UserInterface::UserInterface(string name)
{
	username = name;
	hangarSpace = MAX_HANGAR_SPACE; // Can be adjusted - use in setting difficulty (may also be removed and added in plane class) (if so remove)
	moneySpent = 0.0;
	days = 0;
	hasPlaneCrashed = false;
	userHistory.push_back(name); // adds username to the history of all users who have played the game
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

// function that handles the day to day opperation of the hangar
void UserInterface::hangarOperation()
{
	days++;// incriments the day
	
	for_each(planesInHangar.begin(), planesInHangar.end(), [&](pair<Plane*, int> it) {
		planesInHangar[it.first]--;
		//it.second = it.second - 1; // decrements the number of days remaining on the plane's repair
			if (planesInHangar[it.first] <= 0) // if there are no days remaining for the plane's maintanance, this triggers
			{
				hangarSpace += it.first->getSize();// re adds the space previously taken up by the plane that has now left
				if (!(it.first->getPlaneSafe())) // checking to see if turning the plane away resulted in a plane crash and if so triggering the plane crashed 
				{//flag to end the game
					hasPlaneCrashed = true;
				}
				Plane* tempStorage = (it.first);// temporarily stores the plane pointer 
				planesInHangar.erase(it.first);// removes the plane's entry from the hangar
				delete[] tempStorage; // dealocates heap memory for memory safety
			}
		});
}

// this function handles new planes arriving to the hanger every day
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
	// randomizer fill in done with mulitthreading for speed

	// debug codes
	for (int i = 0; i < 3; ++i) {
		for (int j = 0; j < 2; ++j) {
			cout << aircraftGenerationMatrix[i][j] << " ";
		}
		cout << endl;
	}

	// created 3 new planes that have just arrived at player's hangar
	Plane* newArrivePlane1 = createPlane(aircraftGenerationMatrix[0][0]);
	Plane* newArrivePlane2 = createPlane(aircraftGenerationMatrix[1][0]);
	Plane* newArrivePlane3 = createPlane(aircraftGenerationMatrix[2][0]);
	
	// Getting the issue and allowing the user to select the solution for plane 1
	newArrivePlane1->getIssue(aircraftGenerationMatrix[0][1]);
	newArrivePlane1->possibleSolutions(aircraftGenerationMatrix[0][1]);
	
	if (newArrivePlane1->getSize() > hangarSpace) // checks if the plane will not fit in the hangar
	{
		while (newArrivePlane1->getTime() != 0)// code forces user to turn plane away
		{
			cout << "You do not have enough hangar space for this opperation, you must turn the aircraft away." << endl;
			newArrivePlane1->possibleSolutions(aircraftGenerationMatrix[0][1]);
		}
	}

	if (newArrivePlane1->getTime() == 0) // if the plane was turned away without doing maintanance
	{
		if (!(newArrivePlane1->getPlaneSafe())) // checking to see if turning the plane away resulted in a plane class and if so triggering the plane crashed 
		{//flag to end the game
			hasPlaneCrashed = true;
		}
		delete[] newArrivePlane1; // dealocates for memory safety
	}
	else
	{
		moneySpent += newArrivePlane1->getCost();// adds the cost and time of repair and removes the newly taken up hangar space
		planesInHangar[newArrivePlane1] = newArrivePlane1->getTime();
		hangarSpace -= newArrivePlane1->getSize();
		
	}


	// Getting the issue and allowing the user to select the solution for plane 2
	newArrivePlane2->getIssue(aircraftGenerationMatrix[1][1]);
	newArrivePlane2->possibleSolutions(aircraftGenerationMatrix[1][1]);
	
	if (newArrivePlane2->getSize() > hangarSpace) // checks if the plane will not fit in the hangar
	{
		while (newArrivePlane2->getTime() != 0)// code forces user to turn plane away
		{
			cout << "You do not have enough hangar space for this opperation, you must turn the aircraft away." << endl;
			newArrivePlane2->possibleSolutions(aircraftGenerationMatrix[1][1]);
		}
	}

	if (newArrivePlane2->getTime() == 0) // if the plane was turned away without doing maintanance
	{
		if (!(newArrivePlane2->getPlaneSafe())) // checking to see if turning the plane away resulted in a plane class and if so triggering the plane crashed 
		{//flag to end the game
			hasPlaneCrashed = true;
		}
		delete[] newArrivePlane2; // dealocates for memory safety
	}
	else
	{
		moneySpent += newArrivePlane2->getCost();// adds the cost and time of repair and removes the newly taken up hangar space
		planesInHangar[newArrivePlane2] = newArrivePlane2->getTime();
		hangarSpace -= newArrivePlane2->getSize();

	}



	// Getting the issue and allowing the user to select the solution for plane 3
	newArrivePlane3->getIssue(aircraftGenerationMatrix[2][1]);
	newArrivePlane3->possibleSolutions(aircraftGenerationMatrix[2][1]);
	if (newArrivePlane3->getSize() > hangarSpace) // checks if the plane will not fit in the hangar
	{
		while (newArrivePlane3->getTime() != 0)// code forces user to turn plane away
		{
			cout << "You do not have enough hangar space for this opperation, you must turn the aircraft away." << endl;
			newArrivePlane3->possibleSolutions(aircraftGenerationMatrix[2][1]);
		}
	}

	if (newArrivePlane3->getTime() == 0) // if the plane was turned away without doing maintanance
	{
		if (!(newArrivePlane3->getPlaneSafe())) // checking to see if turning the plane away resulted in a plane class and if so triggering the plane crashed 
		{//flag to end the game
			hasPlaneCrashed = true;
		}
		delete[] newArrivePlane3; // dealocates for memory safety
	}
	else
	{
		moneySpent += newArrivePlane3->getCost();// adds the cost and time of repair and removes the newly taken up hangar space
		planesInHangar[newArrivePlane3] = newArrivePlane3->getTime();
		hangarSpace -= newArrivePlane3->getSize();

	}
}

Plane* UserInterface::createPlane(int planeid)
{
	switch (planeid)
	{
	case 0:
		return new A220IssueandSolutions();
		break;
	case 1:
		return new A320IssueandSolutions();
		break;
	case 2:
		return new A330IssueandSolutions();
		break;
	case 3:
		return new A350IssueandSolutions();
		break;
	case 4:
		return new B737IssueandSolutions();
		break;
	case 5:
		return new B767IssueandSolutions();
		break;
	case 6:
		return new B777IssueandSolutions();
		break;
	case 7:
		return new B787IssueandSolutions();
		break;
	 
	}
}

// destructor added for memory safety
UserInterface::~UserInterface()
{
	for (auto it = planesInHangar.begin(); it != planesInHangar.end(); it++)
	{
		
		
		delete[] it->first; // dealocates heap memory for memory safety for all plane pointers
		

	}
	
}