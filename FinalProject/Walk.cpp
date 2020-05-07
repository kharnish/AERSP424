#include "Walk.h"
#include "Character.h"
#include <iostream>

using namespace std;

//constructor
Walk::Walk() : Character() {

}
double Walk::reducetime(double t) {
	if (type == 'S')
		time = t - 6;
	if (type == 'L')
		time = t - 18;

	return time;
}
double Walk::reducedistance(double d) {
	if (type == 'S')
		distance = d - 0.1;
	if (type == 'L')
		distance = d - 0.3;
	return distance;	// "walk looses less health, but takes longer time and more distance"
}
int Walk::changehealth(int h) {
	if (type == 'S')
		health = h - 5;
	if (type == 'L')
		health = h - 15;
	return health;
}
