#ifndef B757_H
#define B737_H
// include guard
#include <iostream>
#include <vector>
#include "initializer.h"
#include "instructions.h"
#include "plane.h"
#include "userinterface.h"


//problems the B737 plane can have
class B737IssueandSolutions : public Plane
{
private:
	int time;
	int cost;
	bool planeSafe;

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

	// get hangar space
	double getSize() override;
};

#endif // !B737_H