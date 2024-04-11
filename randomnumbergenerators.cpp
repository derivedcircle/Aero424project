#include <array>
#include "randomnumbergenerators.h"
#include <random>
#include <chrono>

using namespace std;

// These functions generate a random number from either 0 to 7 or 0 to 1 for random aircraft generation
void randOf8(array<array<int, 2>, 3> &AGM, int whichAircraft)
{
	std::srand(static_cast<unsigned>(std::chrono::system_clock::now().time_since_epoch().count()));
	int number = rand() >> 28;

	AGM[whichAircraft][0] = number;
}
void randOf2(array<array<int, 2>, 3> &AGM, int whichAircraft)
{
	std::srand(static_cast<unsigned>(std::chrono::system_clock::now().time_since_epoch().count()));
	int number = rand() >> 30;

	AGM[whichAircraft][1] = number;
}