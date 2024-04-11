#ifndef RNG_H
#define RNG_H
// include guard
#include <array>

using namespace std;

// These functions generate a random number from either 0 to 7 or 0 to 1 for random aircraft generation
void randOf8(array<array<int, 2>, 3> &AGM,int whichAircraft);
void randOf2(array<array<int, 2>, 3> &AGM,int whichAircraft);

#endif // !RNG_H
