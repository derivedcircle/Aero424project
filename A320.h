#ifndef A320_H
#define A320_H
// include guard
#include <iostream>
#include <vector>
#include "initializer.h"
#include "instructions.h"
#include "plane.h"
#include "userinterface.h"


//problems the A320 plane can have
class A320IssueandSolutions : public Plane
{
private:
	int time; //keep track of time to fix plane
	int cost; //keep track of cost to fix plane
	bool planeSafe; //keep track of whether plane has crashed or not

public:
	//user chooses number and based off of that, a problem is generated
	void getIssue(int num) override;

	//user must decide on the best course of action to fix the problem above
	void possibleSolutions(int number) override;

	//get cost of repairs
	float getCost() override;

	//get time to repair plane
	int getTime() override;

	//get status of plane safety
	bool getPlaneSafe() override;

	//get hangar space
	double getSize() override;
};

#endif // !A320_H