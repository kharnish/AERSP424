#include "PackBag.h"
#include "Character.h"
#include <iostream>
using namespace std;

//constructor
PackBag::PackBag() : Character() {
}
double PackBag::reducetime(double t) {
	time = t - 10;
	return time;
}