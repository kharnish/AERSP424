#include "Character.h"
#include <cstdlib>
#include <iostream>

//constructor
Character::Character() { }

void Character::settype(char f) {
	if (f == 'b') //breakfast
		type = 'b';
	if (f == 's') //starbz
		type = 's';
	if (f == 'g') //granola
		type = 'g';
	
	if (f == 'B') //bloop
		type = 'B';
	if (f == 'W') //whoop
		type = 'W';
}

Character::~Character() {}