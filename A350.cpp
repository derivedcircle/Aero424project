#include <iostream>
#include <vector>
#include "initializer.h"
#include "instructions.h"
#include "plane.h"
#include "userinterface.h"
#include "A350.h"


//problems the A350 plane can have
//user chooses number and based off of that, a problem is generated
void A350IssueandSolutions::getIssue(int num) {
	while (num != 1 || num != 0)
	{
		std::cout << "Please enter either a 1 or 0" << endl;
		std::cin >> num;
	}
	switch (num) {
	case 0:
		std::cout << "The tire fell off during flight" << endl;
		break;
	case 1:
		std::cout << "There is no fuel" << endl;
		break;
	}
}

//user must decide on the best course of action to fix the problem above
void A350IssueandSolutions::possibleSolutions(int number) {
	char options;
	while (number != 1 || number != 0)
	{
		std::cout << "Please enter either a 1 or 0" << endl;
		std::cin >> number;
	}
	switch (number) {
	//Issue: Engine filled with diesel
	case 0:
		std::cout << "How do you want to solve this issue? Press A to replace the wheel and bolts ($500). Press B to do nothing ($0). Press C to replace the door ($400)" << endl;
		std::cin >> options;
		while (options != 'A' || options != 'B' || options != 'C') {
			std::cout << "Please enter either A, B, or C" << endl;
		}
		switch (options) {
		case 'A':
			time = 7;
			cost = 500;
			issueFixed = true;
			break;
		case 'B':
			time = 0;
			cost = 0;
			issueFixed = false;
			break;
		case 'C':
			time = 7;
			cost = 500;
			issueFixed = false;
			break;
		}
		break;
	case 1:
		//No fuel
		std::cout << "How do you want to solve the issue? Press A to refuel ($50). Press B to do nothing ($0). Press C to replace the whole engine ($500)" << endl;
		std::cin >> options;
		while (options != 'A' || options != 'B' || options != 'C') {
			std::cout << "Please enter either A, B, or C" << endl;
		}
		switch (options) {
		case 'A':
			time = 0;
			cost = 50;
			issueFixed = true;
			break;
		case 'B':
			time = 0;
			cost = 0;
			issueFixed = false;
			break;
		case 'C':
			time = 7;
			cost = 500;
			issueFixed = true;
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