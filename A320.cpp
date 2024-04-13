#include <iostream>
#include <vector>
//include guard
#include "initializer.h"
#include "instructions.h"
#include "plane.h"
#include "userinterface.h"
#include "A320.h"


//problems the A320 plane can have
//user chooses number and based off of that, a problem is generated
void A320IssueandSolutions::getIssue(int num) {
	//while loops to make sure user uses valid number/letter
	while (num != 1 && num != 0)
	{
		std::cout << "Please enter either a 1 or 0" << endl;
		std::cin >> num;
	}
	switch (num) {
	case 0:
		std::cout << "The pilot of the A220 plane (size 500) has reported that a pigeon flew into one of the engines" << endl;
		break;
	case 1:
		std::cout << "The pilot of the A220 plane (size 500) has reported that one of the instruments isn't working" << endl;
		break;
	}
}

//user must decide on the best course of action to fix the problem above
void A320IssueandSolutions::possibleSolutions(int number) {
	char options;
	while (number != 1 && number != 0)
	{
		std::cout << "Please enter either a 1 or 0" << endl;
		std::cin >> number;
	}
	switch (number) {
	//Issue: Pigeons flew into engine
	case 0:
		std::cout << "How do you want to solve this issue?" << endl;
		std::cout << "Press A to replace the engine($500/7 days)." << endl;
		std::cout << "Press B to implement a pigeon shield($100/3 days)." << endl;
		std::cout << "Press C to do nothing($0/0 days)." << endl;
		std::cin >> options;
		while (options != 'A' && options != 'B' && options != 'C') {
			std::cout << "Please enter either A, B, or C" << endl;
		}
		switch (options) {
		case 'A':
			time = 7;
			cost = 500;
			planeSafe = true;
			break;
		case 'B':
			time = 3;
			cost = 50;
			planeSafe = false;
			break;
		case 'C':
			time = 0;
			cost = 0;
			planeSafe = false;
			break;
		}
		break;
	case 1:
		//Issue: Instrument not working
		std::cout << "How do you want to solve the issue?" << endl;
		std::cout << "Press A to do nothing($0/0 days)." << endl;
		std::cout << "Press B to tell passengers to turn on airplane mode($0/1 day)." << endl;
		std::cout << "Press C to replace all of the instruments($300/7 days)" << endl;
		std::cin >> options;
		while (options != 'A' && options != 'B' && options != 'C') {
			std::cout << "Please enter either A, B, or C" << endl;
		}
		switch (options) {
		case 'A':
			time = 0;
			cost = 0;
			planeSafe = true;
			break;
		case 'B':
			time = 1;
			cost = 0;
			planeSafe = true;
			break;
		case 'C':
			time = 7;
			cost = 300;
			planeSafe = true;
			break;
		}
		break;
	}
}

//find cost of repairs
float A320IssueandSolutions::getCost() {
	return cost;
}

//get time spent on repairs
int A320IssueandSolutions::getTime() {
	return time;
}

//get status of plane safety
bool A320IssueandSolutions::getPlaneSafe() {
	return planeSafe;
}

double A320IssueandSolutions::getSize() {
	return 500.0;
}

