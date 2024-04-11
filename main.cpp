#include <iostream>
#include <string>
#include <vector>
//all standard libraries used
#include "plane.h"
#include "initializer.h"
#include "instructions.h"
// all header files to include

using namespace std;
// setting default namespace as standard for convenience


int main()
{
	// holds the username that will be called throughout the program
	string username;
	username = initFun();
	cout << username << endl;
	
	return 0;
}