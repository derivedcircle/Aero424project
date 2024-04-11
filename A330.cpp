#include <iostream>
#include <vector>
#include "initializer.h"
#include "instructions.h"
#include "plane.h"
#include "userinterface.h"
#include "A330.h"


//problems the A330 plane can have
//user chooses number and based off of that, a problem is generated
void A330IssueandSolutions::getIssue(int num) {
	switch (num) {
	case 0:
		std::cout << "The engine was filled with diesel" << endl;
		break;
	case 1:
		std::cout << "There is no fuel" << endl;
		break;
	}
	while (num != 1 || num != 0)
	{
		std::cout << "Please enter either a 1 or 0";
	}
}

//user must decide on the best course of action to fix the problem above
void A330IssueandSolutions::possibleSolutions(int number) {
	char options;
	switch (number) {
		//Issue: Engine filled with diesel
	case 0:
		std::cout << "How do you want to solve this issue? Press A to replace the engine ($500). Press B to do nothing ($0). Press C to flush out the diesel and refuel with the right fuel ($100)." << endl;
		std::cin >> options;
		switch (options) {
		case 'A':
			time = 7;
			cost = 500;
			issueFixed = false;
			break;
		case 'B':
			time = 0;
			cost = 0;
			issueFixed = false;
			break;
		case 'C':
			time = 0;
			cost = 20;
			issueFixed = true;
			break;
		}
		break;
	case 1:
		//No fuel
		std::cout << "How do you want to solve the issue? Press A to refuel ($50). Press B to do nothing ($0). Press C to replace the whole engine ($500)" << endl;
		std::cin >> options;
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
float A330IssueandSolutions::getCost() {
	return cost;
}

//get time spent on repairs
int A330IssueandSolutions::getTime() {
	return time;
}