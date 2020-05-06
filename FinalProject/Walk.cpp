#include "Walk.h"
#include "Character.h"
#include <iostream>

using namespace std;

//constructor
Walk::Walk() : Character() {

}
double Walk::reducetime(double t) {
	time = t - 6;
	return time;
}
double Walk::reducedistance(double d) {
	distance = d - 0.1;						//i changed the distance, and health for both of these but not sure how we're gonna implement the
	return distance;						//"walk looses less health, but takes longer time and more distance"
}
int Walk::changehealth(int h) {
	health = h - 5;
	if (health >= 100)
		health = 100;
	return health;
}