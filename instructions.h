#ifndef INSTRUCTION_H
#define INSTRUCTION_H
// include guard
#include <iostream>
#include <string>
#include <fstream>


using namespace std;

void instructions(const std::string& filename) // makes a function that takes in instructions file
{
	ifstream inFile(filename, ios::in); //opens the file that is declared to be filename 

	if (!inFile) //tests to see if the file opened sucessfully 
	{
		std::cerr << "Failed to open instructions" << filename << std::endl;
		return;
	}

	std::string line; //creates a string holding the current line of text in the instructions file

	while (std::getline(inFile, line)) //repeats until no more lines are left
	{
	std:cout << line << std::endl; //reads each line in the ijnstructions file, stores it in the line string, and prints it to the command window
	}

	inFile.close(); // closes the file when finished with reading it 
}


// void instructions(bool expidite);   <-- what is this for?

int main()
{
	std::string filename = "instructions.txt"; //making a string variable for the instructions file
	instructions(filename); //runs the print instructions function as defined above
}

#endif // !INSTRUCTION_H
