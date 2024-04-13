#include <iostream>
#include <vector>
//include guard
#include "initializer.h"
#include "instructions.h"
#include "plane.h"
#include "userinterface.h"
#include "B787.h"


//problems the B787 plane can have
//user chooses number and based off of that, a problem is generated
void B787IssueandSolutions::getIssue(int num) {
	//while loops to make sure user uses valid number/letter
	while (num != 1 && num != 0)
	{
		std::cout << "Please enter either a 1 or 0" << endl;
		std::cin >> num;
	}
	switch (num) {
	case 0:
		std::cout << "The pilot of the B787 plane (size 650) reports that the right fuel tank is leaking" << endl;
		break;
	case 1:
		std::cout << "The pilot of the B787 plane (size 650) reports that the wing cracked" << endl;
		break;
	}
}

//user must decide on the best course of action to fix the problem above
void B787IssueandSolutions::possibleSolutions(int number) {
	char options;
	while (number != 1 && number != 0)
	{
		std::cout << "Please enter either a 1 or 0" << endl;
		std::cin >> number;
	}
	switch (number) {
	//Issue: Right fuel tank leak
	case 0:
		std::cout << "How do you want to solve this issue?" << endl;
		std::cout << "Press A to run a leak test on the right wing($50/1 day)." << endl;
		std::cout << "Press B to do nothing($0/0 day)." << endl;
		std::cout << "Press C to replace the right aileron($500/7 days)" << endl;
		std::cin >> options;
		while (options != 'A' && options != 'B' && options != 'C') {
			std::cout << "Please enter either A, B, or C" << endl;
		}
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
			planeSafe = false;
			break;
		}
		break;
	case 1:
		//Issue: Wing cracked
		std::cout << "How do you want to solve the issue? " << endl;
		std::cout << "Press A to do nothing($0/0 days)." << endl;
		std::cout << "Press B to replace the fuel tank($400/7 days)." << endl;
		std::cout << "Press C to fix the wing($400/7 days)" << endl;
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
			cost = 400;
			planeSafe = true;
			break;
		}
		break;
	}
}

//find cost of repairs
float B787IssueandSolutions::getCost() {
	return cost;
}

//get time spent on repairs
int B787IssueandSolutions::getTime() {
	return time;
}

//get status of plane safety
bool B787IssueandSolutions::getPlaneSafe() {
	return planeSafe;
}

double B787IssueandSolutions::getSize() {
	return 650.0;
}