#include "Food.h"
#include "Character.h"
#include <iostream>

using namespace std;

//constructor
Food::Food(double t, int h) : Character(t, h) {
	time = t;
	health = h;
}
double Food::reducetime(char f) {
	int fate = 0;
	srand((int) time);
	fate = 1 + (rand() % 100);

	switch (f) {
	case 'b': // breakfast 
		time = time - 30;
	case 's': // Starbucks
		if (fate % 2 == 0) {
			cout << "Good news, the line at Starbucks is short!" << endl;
			time = time - 5;
		}
		else {
			cout << "Yikes, the like at Starbucks is pretty long." << endl;
			time = time - 15;
		}
	}
	if (time <= 0)	{
		cout << "Uh oh! You missed the exam!" << endl;
	}
	return time;
}
int Food::changehealth(char f) {
	if (f == 'b') // breakfast 
		health = health + 15;
	if (f == 's') // Starbucks
		health = health + 10;
	if (f == 'g') // Granola bar
		health = health + 5;

	if (health >= 100)
		health = 100;
	return health;
}