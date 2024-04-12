#include <iostream>
#include <string>
#include <vector>
//all standard libraries used
#include "plane.h"
#include "initializer.h"
#include "instructions.h"
#include "userinterface.h"
// all header files to include
// hello :)

using namespace std;
// setting default namespace as standard for convenience


int main()
{
	UserInterface user1(initFun());
	cout << user1 << endl;
	user1.hangarOperation();
	cout << user1 << endl;
	user1.newAircraftArrivals();
	user1.hangarOperation();
	cout << user1 << endl;
	
	return 0;
}