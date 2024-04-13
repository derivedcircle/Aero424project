#include <iostream>
#include <vector>
//include guard
#include "initializer.h"
#include "instructions.h"
#include "plane.h"
#include "userinterface.h"
#include "B767.h"


//problems the B767 plane can have
//user chooses number and based off of that, a problem is generated
void B767IssueandSolutions::getIssue(int num) {
	//while loops to make sure user uses valid number/letter
	while (num != 1 && num != 0)
	{
		std::cout << "Please enter either a 1 or 0" << endl;
		std::cin >> num;
	}
	switch (num) {
	case 0:
		std::cout << "The pilot of the B767 plane (size 550) just discovered a trap door near a passenger seat" << endl;
		break;
	case 1:
		std::cout << "The pilot of the B767 plane (size 550) reports that one of the windows cracked" << endl;
		break;
	}
}

//user must decide on the best course of action to fix the problem above
void B767IssueandSolutions::possibleSolutions(int number) {
	char options;
	while (number != 1 && number != 0)
	{
		std::cout << "Please enter either a 1 or 0" << endl;
		std::cin >> number;
	}
	switch (number) {
	//Issue: Trap door
	case 0:
		std::cout << "How do you want to solve this issue?" << endl;
		std::cout << "Press A to do nothing($0/0 days)." << endl;
		std::cout << "Press B to give the passengers a parachute and wish them luck($100/1 day)." << endl;
		std::cout << "Press C to inspect and replace($1000/30 days)" << endl;
		std::cin >> options;
		while (options != 'A' && options != 'B' && options != 'C') {
			std::cout << "Please enter either A, B, or C" << endl;
			std::cin >> options;
		}
		switch (options) {
		case 'A':
			time = 0;
			cost = 0;
			planeSafe = false;
			break;
		case 'B':
			time = 1;
			cost = 100;
			planeSafe = false;
			break;
		case 'C':
			time = 30;
			cost = 1000;
			planeSafe = true;
			break;
		}
		break;
	case 1:
		//Issue: Window crack
		std::cout << "How do you want to solve the issue?" << endl;
		std::cout << "Press A to duct tape the window($5/1 day)." << endl;
		std::cout << "Press B to do nothing($0/0 days)." << endl;
		std::cout << "Press C to replace the window($100/3 days)" << endl;
		std::cin >> options;
		while (options != 'A' && options != 'B' && options != 'C') {
			std::cout << "Please enter either A, B, or C" << endl;
			std::cin >> options;
		}
		switch (options) {
		case 'A':
			time = 1;
			cost = 5;
			planeSafe = false;
			break;
		case 'B':
			time = 0;
			cost = 0;
			planeSafe = false;
			break;
		case 'C':
			time = 3;
			cost = 100;
			planeSafe = true;
			break;
		}
		break;
	}
}

//find cost of repairs
float B767IssueandSolutions::getCost() {
	return cost;
}

//get time spent on repairs
int B767IssueandSolutions::getTime() {
	return time;
}

//get status of plane safety
bool B767IssueandSolutions::getPlaneSafe() {
	return planeSafe;
}

double B767IssueandSolutions::getSize() {
	return 550.0;
}