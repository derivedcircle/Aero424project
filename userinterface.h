#ifndef UI_H
#define UI_H
// include guard
#include <iostream>
#include <string>
#include <map>

using namespace std;

class UserInterface
{
	string username;
	double hangarSpace;
	float moneySpent;
	int days;
	// a map with the planes in the hanger and how many days it will take to do their maintanance
public:
	UserInterface( string name);
	void displayCurrStatus();// function that displays the current status of the aircraft in the hangar (replace with an opperator override)
	void newAircraftArrivals();// function that creates new aircraft to pick from 
};

#endif // !UI_H
