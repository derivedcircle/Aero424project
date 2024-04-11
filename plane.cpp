#include <iostream>

class plane
{
	virtual void getIssue() = 0;
	virtual void possibleSolutions() = 0;
	virtual void getSize();
	virtual void costImplentation();
	virtual ~plane();
};