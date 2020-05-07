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
		if (fate >= 80) {
			cout << "Oh no, the bus driver is getting out to switch! This will take even longer now." << endl;
			time = t - 25;
		}
		else if(fate >= 40) {
			cout << "Traffic is pretty bad today on Atherton." << endl;
			time = t - 15;
		}
		else {
			cout << "Looks like you made the right choice, at least for today." << endl;
			time = t - 10;
		}
	}
	if (type == 'W')
	{
		if (fate >= 70) {
			cout << "Oh no, the bus driver is getting out to switch! This will take even longer now." << endl;
			time = t - 25;
		}
		else if (fate >= 40) {
			cout << "Traffic is pretty bad today on College." << endl;
			time = t - 20;
		}
		else {
			cout << "Looks like you made the right choice, at least for today." << endl;
			time = t - 15;
		}
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