#include <iostream>
#include <vector>
#include "initializer.h"
#include "instructions.h"
#include "plane.h"
#include "userinterface.h"
#include "A320.h"


//problems the A320 plane can have
//user chooses number and based off of that, a problem is generated
void A320IssueandSolutions::getIssue(int num) {
	switch (num) {
	case 0:
		std::cout << "A pigeon flew into one of the engines" << endl;
		break;
	case 1:
		std::cout << "One of the instruments isn't working" << endl;
		break;
	}
	while (num != 1 || num != 0)
	{
		std::cout << "Please enter either a 1 or 0";
	}
}

//user must decide on the best course of action to fix the problem above
void A320IssueandSolutions::possibleSolutions(int number) {
	char options;
	switch (number) {
	//Issue: Pigeons flew into engine
	case 0:
		std::cout << "How do you want to solve this issue? Press A to replace the engine ($500). Press B to implement a pigeon shield ($100). Press C to do nothing ($0)." << endl;
		std::cin >> options;
		switch (options) {
		case 'A':
			time = 7;
			cost = 500;
			issueFixed = true;
			break;
		case 'B':
			time = 3;
			cost = 50;
			issueFixed = false;
			break;
		case 'C':
			time = 0;
			cost = 0;
			issueFixed = false;
			break;
		}
		break;
	case 1:
		//Door flew off during flight
		std::cout << "How do you want to solve the issue? Press A to do nothing ($0). Press B to replace the door and paint over any problematic bolts ($100). Press C to replace the door as well as problematic bolts in other areas of the plane ($200)" << endl;
		std::cin >> options;
		switch (options) {
		case 'A':
			time = 0;
			cost = 0;
			issueFixed = false;
			break;
		case 'B':
			time = 2;
			cost = 100;
			issueFixed = false;
			break;
		case 'C':
			time = 4;
			cost = 200;
			issueFixed = true;
			break;
		}
		while (options != 'A' || options != 'B' || options != 'C')
		{
			cout << "Please choose A,B, or C depending on which option you think is best.";
		}
		break;
	}
	while (number != 1 || number != 0)
	{
		std::cout << "Please enter either a 1 or 0";
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
