#ifndef UI_H
#define UI_H
// include guard
#include <iostream>
#include <string>
#include <map>
#include "plane.h"

using namespace std;

class UserInterface
{
	
	string username;
	const double MAX_HANGAR_SPACE = 1000.0; // Can be adjusted - use in setting difficulty (may also be removed and added in plane class) (if so remove)
	double hangarSpace;
	float moneySpent;
	int days;
	// a map with the planes in the hanger and how many days are remaining to do their maintanance
	map<Plane*, int> planesInHangar;
	
public:

	bool hasPlaneCrashed;

	UserInterface( string name);// UI constructor
	
	friend ostream& operator<<(ostream& os, const UserInterface& obj); // operator overload that allows a cout command output the 
	//current status of the aircraft in the hangar and user metrics
	
	void newAircraftArrivals();// function that creates new aircraft to pick from 

	void hangarOperation(); // function that goes through and decrements all aircraft maintanance times 
};

#endif // !UI_H
