#include "Run.h"
#include "Character.h"
#include <iostream>

using namespace std;

//constructor
Run::Run(double t, int h) : Character(t, h) {
	time = t;
	health = h;
}
double Run::reducetime() {
	time = time - 0.5;
	if (time <= 0) {
		cout << "Uh oh! You missed the exam!" << endl;
	}
	return time;
}
int Run::changehealth() {
	health = health + 15;
	if (health >= 100)
		health = 100;
	return health;
}