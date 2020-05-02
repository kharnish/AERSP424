#include "Food.h"
#include "Character.h"
#include <iostream>

using namespace std;

//constructor
Food::Food() : Character() {

}
double Food::reducetime(double t) {
	int fate = 0;
	srand((int) time);
	fate = 1 + (rand() % 100);

	switch (type) {
	case 'b': // breakfast 
		time = t - 30;
		break;
	case 's': // Starbucks
		if (fate % 2 == 0) {
			cout << "Good news, the line at Starbucks is short!" << endl;
			time = t - 5;
		}
		else {
			cout << "Yikes, the like at Starbucks is pretty long." << endl;
			time = t - 15;
		}
		break;
	}
	return time;
}
int Food::changehealth(int h) {
	if (type == 'b') // breakfast		//type is determined by Character.cpp
		health = h + 15;
	if (type == 's') // Starbucks
		health = h + 10;
	if (type == 'g') // Granola bar
		health = h + 5;

	if (h >= 100)
		health = 100;
	return health;
}