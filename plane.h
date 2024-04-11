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
	virtual ~Plane();
};

#endif // !Plane_H
