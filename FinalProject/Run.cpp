#include "Run.h"
#include "Character.h"
#include <iostream>

using namespace std;

//constructor
Run::Run() : Character() {

}
double Run::reducetime(double t) {
	if (type == 'S')
		time = t - 3;
	if (type == 'L')
		time = t - 9; 
	return time;
}
double Run::reducedistance(double d) {
	if (type == 'S')
		distance = d - 0.1;
	if (type == 'L')
		distance = d - 0.3;
	return distance;
}
int Run::changehealth(int h) {
	if (type == 'S')
		health = h - 7;
	if (type == 'L')
		health = h - 21;
	return health;
}