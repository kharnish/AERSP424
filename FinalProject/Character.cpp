#include "Character.h"
#include <cstdlib>

//constructor
Character::Character() {}

//Character::Character(double t) {
//	time = t;
//}
//Character::Character(double t, int h) {
//	time = t;
//	health = h;
//}
//Character::Character(double t, int h, int m) {
//	time = t;
//	health = h;
//	money = m;
//}
//Character::Character(double t, int h, char f) {
//	time = t;
//	health = h;
//	type = f;
//}
//Character::Character(double t, double d, int h, int m) {
//	time = t;
//	distance = d;
//	health = h;
//	money = m;
//}

void Character::settype(char f) {
	if (f == 'b')
		type = 'b';
	if (f == 's')
		type = 's';
	if (f == 'g')
		type = 'g';
}

Character::~Character() {}