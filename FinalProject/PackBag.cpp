#include "PackBag.h"
#include "Character.h"
#include <iostream>
using namespace std;

//constructor
PackBag::PackBag(double t) : Character(t) {
	time = t;
}
double PackBag::reducetime() {
	time = time - 0.167;
	if (time <= 0) {
		cout << "Uh oh! You missed the exam!" << endl;
		return 0;
	}
	return time;
}