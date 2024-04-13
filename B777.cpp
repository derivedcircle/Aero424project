#include <iostream>
#include <vector>
//include guard
#include "initializer.h"
#include "instructions.h"
#include "plane.h"
#include "userinterface.h"
#include "B777.h"


//problems the B777 plane can have
//user chooses number and based off of that, a problem is generated
void B777IssueandSolutions::getIssue(int num) {
	//while loops to make sure user uses valid number/letter
	while (num != 1 && num != 0)
	{
		std::cout << "Please enter either a 1 or 0" << endl;
		std::cin >> num;
	}
	switch (num) {
	case 0:
		std::cout << "The pilot of the B777 plane (size 700) reports that the window is dirty and he can't see" << endl;
		break;
	case 1:
		std::cout << "The pilot of the B777 plane (size 700) reports that the septic tank is leaking" << endl;
		break;
	}
}

//user must decide on the best course of action to fix the problem above
void B777IssueandSolutions::possibleSolutions(int number) {
	char options;
	while (number != 1 && number != 0)
	{
		std::cout << "Please enter either a 1 or 0" << endl;
		std::cin >> number;
	}
	switch (number) {
	//Issue: Window dirty
	case 0:
		std::cout << "How do you want to solve this issue?" << endl;
		std::cout << "Press A to tell the pilots to get prescription glasses($0/0 day)." << endl;
		std::cout << "Press B to clean the window($30/1 day)." << endl;
		std::cout << "Press C to replace the window($300/7 days)" << endl;
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
			time = 1;
			cost = 30;
			planeSafe = true;
			break;
		case 'C':
			time = 7;
			cost = 300;
			planeSafe = true;
			break;
		}
		break;
	case 1:
		//Issue: Septic tank leak
		std::cout << "How do you want to solve the issue? " << endl;
		std::cout << "Press A to wish the passengers good luck($0/0 days)." << endl;
		std::cout << "Press B to replace the fuel tank($400/7 days)." << endl;
		std::cout << "Press C to replace the septic tank($200/7 days)" << endl;
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
			time = 7;
			cost = 400;
			planeSafe = false;
			break;
		case 'C':
			time = 7;
			cost = 200;
			planeSafe = true;
			break;
		}
		break;
	}
}

//find cost of repairs
float B777IssueandSolutions::getCost() {
	return cost;
}

//get time spent on repairs
int B777IssueandSolutions::getTime() {
	return time;
}

//get status of plane safety
bool B777IssueandSolutions::getPlaneSafe() {
	return planeSafe;
}

double B777IssueandSolutions::getSize() {
	return 700.0;
}