#include "Run.h"
#include "Character.h"
#include <iostream>

using namespace std;

//constructor
Run::Run() : Character() {

}
double Run::reducetime(double t) {
	time = t - 3;
	return time;
}
double Run::reducedistance(double d) {
	distance = d - 0.1;
	return distance;
}
int Run::changehealth(int h) {
	health = h - 7;
	if (h >= 100)
		health = 100;
	return health;
}