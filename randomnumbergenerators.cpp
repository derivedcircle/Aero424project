#include <array>
#include "randomnumbergenerators.h"
#include <random>
#include <chrono>

using namespace std;

// These functions generate a random number from either 0 to 7 or 0 to 1 for random aircraft generation
void randOf8(array<array<int, 2>, 3> &AGM, int whichAircraft)
{
	// seeds randomizer to current time
	std::srand(static_cast<unsigned>(std::chrono::system_clock::now().time_since_epoch().count()));
	
	int number = static_cast<unsigned short>(rand()*2) >> 13; // takes the random intiger and shifts to the right 13 times, resulting a number from 0 to 7
	// the static cast to a unsighned short is required as rand's upper limit is not standardized but this will be guarenteed to work with any value for RAND_MAX
	// from the standardized minimum value up and output the same value
	AGM[whichAircraft][0] = number; // stores that number in the Aircraft generation matrix
}
void randOf2(array<array<int, 2>, 3> &AGM, int whichAircraft)
{
	// seeds randomizer to current time
	std::srand(static_cast<unsigned>(std::chrono::system_clock::now().time_since_epoch().count()));
	int number = static_cast<unsigned short>(rand()*2) >> 15; // takes the random intiger and shifts to the right 15 times, resulting in a number from 0 to 1
	// the static cast to a unsighned short is required as rand's upper limit is not standardized but this will be guarenteed to work with any value for RAND_MAX
	// from the standardized minimum value up and output the same value
	AGM[whichAircraft][1] = number; // stores that number in the Aircraft generation matrix
}