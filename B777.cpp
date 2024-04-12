#include <iostream>
#include <vector>
#include "initializer.h"
#include "instructions.h"
#include "plane.h"
#include "userinterface.h"
#include "B777.h"


//problems the B777 plane can have
//user chooses number and based off of that, a problem is generated
void B777IssueandSolutions::getIssue(int num) {
	while (num != 1 || num != 0)
	{
		std::cout << "Please enter either a 1 or 0" << endl;
		std::cin >> num;
	}
	switch (num) {
	case 0:
		std::cout << "The window is dirty and the pilots can't see" << endl;
		break;
	case 1:
		std::cout << "The septic tank is leaking" << endl;
		break;
	}
}

//user must decide on the best course of action to fix the problem above
void B777IssueandSolutions::possibleSolutions(int number) {
	char options;
	while (number != 1 || number != 0)
	{
		std::cout << "Please enter either a 1 or 0" << endl;
		std::cin >> number;
	}
	switch (number) {
	//Issue: Window dirty
	case 0:
		std::cout << "How do you want to solve this issue? Press A to tell the pilots to get prescription glasses ($0). Clean the window ($30).Press C to replace the window ($300)" << endl;
		std::cin >> options;
		while (options != 'A' || options != 'B' || options != 'C') {
			std::cout << "Please enter either A, B, or C" << endl;
		}
		switch (options) {
		case 'A':
			time = 0;
			cost = 0;
			planeSafe = false;
			break;
		case 'B':
			time = 0;
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
		//Septic tank leak
		std::cout << "How do you want to solve the issue? Press A to wish the passengers good luck ($0). Press B to replace the fuel tank ($400). Press C to replace the septic tank ($200)" << endl;
		std::cin >> options;
		while (options != 'A' || options != 'B' || options != 'C') {
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