#include "Bus.h"
#include "Character.h"
#include <iostream>
using namespace std;

//constructor
Bus::Bus() : Character() {
}
double Bus::reducetime(double t) {
	int fate = 0;
	srand((int)time);
	fate = 1 + (rand() % 100);
	
	if (type == 'B')
	{
		//will add fate stuff like if theres a driver change
	}
	if (type == 'W')
	{
		//will add fate stuff like if theres a driver change
	}
	return time;
}
double Bus::reducedistance(double d) {
	if (type == 'B') //stops at library
	{
		distance = d - 0.6;
	}
	if (type == 'W') //stops at kern
	{
		distance = d - 0.5;
	}
	return distance;
}