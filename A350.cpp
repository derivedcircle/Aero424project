#include <iostream>
#include <vector>
//include guard
#include "initializer.h"
#include "instructions.h"
#include "plane.h"
#include "userinterface.h"
#include "A350.h"


//problems the A350 plane can have
//user chooses number and based off of that, a problem is generated
void A350IssueandSolutions::getIssue(int num) {
	//while loops to make sure user uses valid number/letter
	while (num != 1 && num != 0)
	{
		std::cout << "Please enter either a 1 or 0" << endl;
		std::cin >> num;
	}
	switch (num) {
	case 0:
		std::cout << "The pilot of the A350 plane (size 800) has reported that the tire fell off during flight" << endl;
		break;
	case 1:
		std::cout << "The pilot of the A350 plane (size 800) has reported that the plane scraped the ground upon takeoff" << endl;
		break;
	}
}

//user must decide on the best course of action to fix the problem above
void A350IssueandSolutions::possibleSolutions(int number) {
	char options;
	while (number != 1 && number != 0)
	{
		std::cout << "Please enter either a 1 or 0" << endl;
		std::cin >> number;
	}
	switch (number) {
	//Issue: tire fell off
	case 0:
		std::cout << "How do you want to solve this issue? " << endl;
		std::cout << "Press A to replace the wheel and bolts($500/7 days)." << endl;
		std::cout << "Press B to do nothing($0/0 days)." << endl;
		std::cout << "Press C to replace the door($400/7 days)" << endl;
		std::cin >> options;
		while (options != 'A' && options != 'B' && options != 'C') {
			std::cout << "Please enter either A, B, or C" << endl;
			std::cin >> options;
		}
		//use switch to keep track of time and money spent, as well as whether plane has been destroyed
		switch (options) {
		case 'A':
			time = 7;
			cost = 500;
			planeSafe = true;
			break;
		case 'B':
			time = 0;
			cost = 0;
			planeSafe = false;
			break;
		case 'C':
			time = 7;
			cost = 500;
			planeSafe = false;
			break;
		}
		break;
	case 1:
		//Issue: plane scraped ground upon takeoff
		std::cout << "How do you want to solve the issue? " << endl;
		std::cout << "Press A to do a general check for damage and replace damaged parts($500/7 days)." << endl;
		std::cout << "Press B to do nothing($0/0 days)." << endl;
		std::cout << "Press C to drill a hole in the fuselage($250/2 days)" << endl;
		std::cin >> options;
		while (options != 'A' && options != 'B' && options != 'C') {
			std::cout << "Please enter either A, B, or C" << endl;
			std::cin >> options;
		}
		//use switch to keep track of time and money spent, as well as whether plane has been destroyed
		switch (options) {
		case 'A':
			time = 7;
			cost = 500;
			planeSafe = true;
			break;
		case 'B':
			time = 0;
			cost = 0;
			planeSafe = true;
			break;
		case 'C':
			time = 2;
			cost = 250;
			planeSafe = false;
			break;
		}
		break;
	}
}

//find cost of repairs
float A350IssueandSolutions::getCost() {
	return cost;
}

//get time spent on repairs
int A350IssueandSolutions::getTime() {
	return time;
}

//get status of plane safety
bool A350IssueandSolutions::getPlaneSafe() {
	return planeSafe;
}

//get size of plane
double A350IssueandSolutions::getSize() {
	return 800.0;
}