#include "Dressed.h"
#include "Character.h"
#include <iostream>
using namespace std;

//constructor
Dressed::Dressed(double t) : Character(t) {
	time = t;
}
double Dressed::reducetime() {
	time = time - 20;
	if (time <= 0) {
		cout << "Uh oh! You missed the exam!" << endl;
		return 0;
	}
	return time;
}