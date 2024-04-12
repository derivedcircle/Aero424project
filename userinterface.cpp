#include "userinterface.h"
#include <array>
#include <thread>
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
		if (it->second <= 0)
		{
			//what happens when the plane completes it maintanance (it leaves and check if it will crash after)
			delete[] it->first; // dealocates heap memory for memory safety
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

	// created 3 new planes that have just arrived at player's hangar
	Plane* newArrivePlane1 = createPlane(aircraftGenerationMatrix[0][0]);
	Plane* newArrivePlane2 = createPlane(aircraftGenerationMatrix[1][0]);
	Plane* newArrivePlane3 = createPlane(aircraftGenerationMatrix[2][0]);
	
	// we are getting the issues, allowing the user to select the solution and then noting down how much money the user spends and putting the plane into our hangar
	newArrivePlane1->getIssue(aircraftGenerationMatrix[0][1]);
	newArrivePlane1->possibleSolutions(aircraftGenerationMatrix[0][1]);
	moneySpent += newArrivePlane1->getCost();
	planesInHangar[newArrivePlane1] = newArrivePlane1->getTime();
	// something to handle hangar space taken up and logic if there is no hangar space remaining
	// also some logic to handle if you turn a plane away (check if plane is safe)

	newArrivePlane2->getIssue(aircraftGenerationMatrix[1][1]);
	newArrivePlane2->possibleSolutions(aircraftGenerationMatrix[1][1]);
	moneySpent += newArrivePlane2->getCost();
	planesInHangar[newArrivePlane2] = newArrivePlane2->getTime();
	// something to handle hangar space taken up and logic if there is no hangar space remaining
	// also some logic to handle if you turn a plane away (check if plane is safe)

	newArrivePlane3->getIssue(aircraftGenerationMatrix[2][1]);
	newArrivePlane3->possibleSolutions(aircraftGenerationMatrix[2][1]);
	moneySpent += newArrivePlane3->getCost();
	planesInHangar[newArrivePlane3] = newArrivePlane3->getTime();
	// something to handle hangar space taken up and logic if there is no hangar space remaining
	// also some logic to handle if you turn a plane away (check if plane is safe)
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