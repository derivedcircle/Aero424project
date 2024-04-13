#include <iostream>
#include <vector>
//include guard
#include "initializer.h"
#include "instructions.h"
#include "plane.h"
#include "userinterface.h"
#include "A220.h"


//problems the A220 plane can have
//user chooses number and based off of that, a problem is generated
void A220IssueandSolutions::getIssue(int num) {
	//while loops to make sure user uses valid number/letter
	while (num != 1 && num != 0)
	{
		std::cout << "Please enter either a 1 or 0" << endl;
		std::cin >> num;
	}
	switch (num){
	case 0:
		std::cout << "The pilot of the A220 plane (size 300) has reported that his plane flew through a drone show" << endl;
		break;
	case 1:
		std::cout << "The pilot of the A220 plane (size 300) has reported that one of the doors on the plane flew off." << endl;
		break;
	}
}

//user must decide on the best course of action to fix the problem above
void A220IssueandSolutions::possibleSolutions(int number) {
	char options;
	while (number != 1 && number != 0)
	{
		std::cout << "Please enter either a 1 or 0" << endl;
		std::cin >> number;
	}
	switch (number) {
	//Issue: Plane flew into drone show
	case 0:
		std::cout << "How do you want to solve this issue?" << endl;
		std::cout << "Press A to install a drone shield($1000/30 days)." << endl;
		std::cout << "Press B to inspect the plane for damages($100/7 days)." << endl;
		std::cout << "Press C to do nothing($0/0 days)." << endl;
		std::cin >> options;
		while (options != 'A' && options != 'B' && options != 'C') {
			std::cout << "Please enter either A, B, or C" << endl;
		}
		switch (options) {
		case 'A':
			time = 30;
			cost = 1000;
			planeSafe = true;
			break;
		case 'B':
			time = 7;
			cost = 100;
			planeSafe = true;
			break;
		case 'C':
			time = 0;
			cost = 0;
			planeSafe = true;
			break;
		}
		break;
	case 1:
		//Issue: Door flew off during flight
		std::cout << "How do you want to solve the issue?" << endl;
		std::cout << "Press A to do nothing($0/0 days)." << endl;
		std::cout << "Press B to replace the door and paint over any problematic bolts($100/2 days)." << endl;
		std::cout << "Press C to replace the door as well as problematic bolts in other areas of the plane($200/4 days)" << endl;
		std::cin >> options;
		while (options != 'A' && options != 'B' && options != 'C') {
			std::cout << "Please enter either A, B, or C" << endl;
		}
		switch (options) {
		case 'A':
			time = 0;
			cost = 0;
			planeSafe = false;
			break;
		case 'B':
			time = 2;
			cost = 100;
			planeSafe = false;
			break;
		case 'C':
			time = 4;
			cost = 200;
			planeSafe = true;
			break;
		}
		break;
	}
}

//find cost of repairs
float A220IssueandSolutions::getCost() {
	return cost;
}

//get time spent on repairs
int A220IssueandSolutions::getTime() {
	return time;
}

//get status of plane safety
bool A220IssueandSolutions::getPlaneSafe() {
	return planeSafe;
}

double A220IssueandSolutions::getSize() {
	return 300.0;
}
