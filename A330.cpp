#include <iostream>
#include <vector>
//include guard
#include "initializer.h"
#include "instructions.h"
#include "plane.h"
#include "userinterface.h"
#include "A330.h"


//problems the A330 plane can have
//user chooses number and based off of that, a problem is generated
void A330IssueandSolutions::getIssue(int num) {
	//while loops to make sure user uses valid number/letter
	while (num != 1 && num != 0)
	{
		std::cout << "Please enter either a 1 or 0" << endl;
		std::cin >> num;
	}
	switch (num) {
	case 0:
		std::cout << "The pilot of the A330 plane (size 600) has reported that the engine was filled with diesel" << endl;
		break;
	case 1:
		std::cout << "The pilot of the A330 plane (size 600) has reported that there is no fuel" << endl;
		break;
	}
}

//user must decide on the best course of action to fix the problem above
void A330IssueandSolutions::possibleSolutions(int number) {
	char options;
	while (number != 1 && number != 0)
	{
		std::cout << "Please enter either a 1 or 0" << endl;
		std::cin >> number;
	}
	switch (number) {
	//Issue: Engine filled with diesel
	case 0:
		std::cout << "How do you want to solve this issue?" << endl;
		std::cout << "Press A to replace the engine($500/7 days)." << endl;
		std::cout << "Press B to do nothing($0/0 days)." << endl;
		std::cout << "Press C to flush out the diesel and refuel with the right fuel($100/1 day)." << endl;
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
			time = 0;
			cost = 0;
			planeSafe = false;
			break;
		case 'C':
			time = 1;
			cost = 20;
			planeSafe = true;
			break;
		}
		break;
	case 1:
		//Issue: No fuel
		std::cout << "How do you want to solve the issue?" << endl;
		std::cout << "Press A to refuel($50/1 day)." << endl;
		std::cout << "Press B to do nothing($0/0 days)." << endl;
		std::cout << "Press C to replace the whole engine($500/7 days)" << endl;
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
			planeSafe = true;
			break;
		}
		break;
	}
}

//find cost of repairs
float A330IssueandSolutions::getCost() {
	return cost;
}

//get time spent on repairs
int A330IssueandSolutions::getTime() {
	return time;
}

//get status of plane safety
bool A330IssueandSolutions::getPlaneSafe() {
	return planeSafe;
}

double A330IssueandSolutions::getSize() {
	return 600.0;
}
