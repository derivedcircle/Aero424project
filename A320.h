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

	float getCost() override;

	int getTime() override;
};

#endif // !A320_H