#include "Character.h"
#include <cstdlib>

//constructor
Character::Character(double t) {
	time = t;
}
Character::Character(double t, int h) {
	time = t;
	health = h;
}
Character::Character(double t, double d, int h, int m) {
	time = t;
	distance = d;
	health = h;
	money = m;
}

Character::~Character() {}