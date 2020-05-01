#include "Food.h"
#include "Character.h"
#include <iostream>

using namespace std;

//constructor
Food::Food(double t, int h) : Character(t, h) {
	time = t;
	health = h;
}
double Food::reducetime() {
	time = time - 0.5;
	if (time <= 0) {
		cout << "Uh oh! You missed the exam!" << endl;
	}
	return time;
}
int Food::changehealth() {
	health = health + 15;
	if (health >= 100)
		health = 100;
	return health;
}