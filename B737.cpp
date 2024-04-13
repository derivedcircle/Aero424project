#include <iostream>
#include <vector>
//include guard
#include "initializer.h"
#include "instructions.h"
#include "plane.h"
#include "userinterface.h"
#include "B737.h"


//problems the B737 plane can have
//user chooses number and based off of that, a problem is generated
void B737IssueandSolutions::getIssue(int num) {
	//while loops to make sure user uses valid number/letter
	while (num != 1 && num != 0)
	{
		std::cout << "Please enter either a 1 or 0" << endl;
		std::cin >> num;
	}
	switch (num) {
	case 0:
		std::cout << "The pilot of the B737 plane (size 400) has reported that the navigation system failed" << endl;
		break;
	case 1:
		std::cout << "The pilot of the B737 plane (size 400) has reported that the left fuel tank has a leak" << endl;
		break;
	}
}

//user must decide on the best course of action to fix the problem above
void B737IssueandSolutions::possibleSolutions(int number) {
	char options;
	while (number != 1 && number != 0)
	{
		std::cout << "Please enter either a 1 or 0" << endl;
		std::cin >> number;
	}
	switch (number) {
		//Issue: Navigation system failed
	case 0:
		std::cout << "How do you want to solve this issue? " << endl;
		std::cout << "Press A to do nothing($0/0 days)" << endl;
		std::cout << "Press B for 'What's our vector, Victor?'($0/1 day)" << endl;
		std::cout << "Press C to replace the navigation system($500/7 days)" << endl;
		std::cin >> options;
		while (options != 'A' && options != 'B' && options != 'C') {
			std::cout << "Please enter either A, B, or C" << endl;
			std::cin >> options;
		}
		//use switch to keep track of time and money spent, as well as whether plane has been destroyed
		switch (options) {
		case 'A':
			time = 0;
			cost = 0;
			planeSafe = true;
			break;
		case 'B':
			time = 1;
			cost = 0;
			planeSafe = false;
			break;
		case 'C':
			time = 7;
			cost = 500;
			planeSafe = true;
			break;
		}
		break;
	case 1:
		//Issue: Left fuel tank leak
		std::cout << "How do you want to solve the issue? " << endl;
		std::cout << "Press A to run a leak test on the left wing($50/1 day)." << endl;
		std::cout << "Press B to do nothing($0/0 days)." << endl;
		std::cout << "Press C to replace the left aileron($500/7 days)" << endl;
		std::cin >> options;
		while (options != 'A' && options != 'B' && options != 'C') {
			std::cout << "Please enter either A, B, or C" << endl;
			std::cin >> options;
		}
		//use switch to keep track of time and money spent, as well as whether plane has been destroyed
		switch (options) {
		case 'A':
			time = 1;
			cost = 50;
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
			planeSafe = true;
			break;
		}
		break;
	}
}

//find cost of repairs
float B737IssueandSolutions::getCost() {
	return cost;
}

//get time spent on repairs
int B737IssueandSolutions::getTime() {
	return time;
}

//get status of plane safety
bool B737IssueandSolutions::getPlaneSafe() {
	return planeSafe;
}

//get size of plane
double B737IssueandSolutions::getSize() {
	return 400.0;
}
