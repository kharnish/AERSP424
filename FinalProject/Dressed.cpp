#include "Dressed.h"
#include "Character.h"
#include <iostream>
using namespace std;

//constructor
Dressed::Dressed() : Character() {
}
double Dressed::reducetime(double t) {
	time = t - 20;
	return time;
}