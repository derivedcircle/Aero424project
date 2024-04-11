#ifndef B787_H
#define B787_H
// include guard
#include <iostream>
#include <vector>
#include "initializer.h"
#include "instructions.h"
#include "plane.h"
#include "userinterface.h"


//problems the B787 plane can have
class B787IssueandSolutions : public Plane
{
private:
	int time;
	int cost;

public:
	bool issueFixed;

	//user chooses number and based off of that, a problem is generated
	void getIssue(int num) override;

	//user must decide on the best course of action to fix the problem above
	void possibleSolutions(int number) override;

	//get cost of repairs
	float getCost() override;

	//get time to repair plane
	int getTime() override;
};

#endif // !B787_H