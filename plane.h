#include <iostream>
#ifndef Plane_H
#define Plane_H
//include guards

class Plane
{
public:
	virtual void getIssue(int num) = 0;
	virtual void possibleSolutions(int number) = 0;
	virtual float getCost() = 0;
	virtual int getTime() = 0;
	virtual bool getPlaneSafe() = 0;
};

#endif // !Plane_H
