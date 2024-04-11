#ifndef A350_H
#define A350_H
// include guard
#include <iostream>
#include <vector>
#include "initializer.h"
#include "instructions.h"
#include "plane.h"
#include "userinterface.h"


//problems the A350 plane can have
class A350IssueandSolutions : public Plane
{
private:
	int time;
	int cost;

public:
	bool issueFixed;
	int time;
	int cost;

	//user chooses number and based off of that, a problem is generated
	void getIssue(int num) override;

	//user must decide on the best course of action to fix the problem above
	void possibleSolutions(int number) override;

	//get cost of repairs
	float getCost() override;

	//get time to repair plane
	int getTime() override;
};

#endif // !A350_H