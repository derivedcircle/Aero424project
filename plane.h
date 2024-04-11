#include <iostream>
#ifndef plane_H
#define plane_H
//include guards

class plane
{
	virtual void getIssue() = 0;
	virtual void possibleSolutions() = 0;
	virtual void getSize() = 0;
	virtual void costImplentation() = 0;
	virtual ~plane();
};

#endif // !plane_H
