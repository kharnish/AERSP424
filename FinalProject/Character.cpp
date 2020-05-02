#include "Character.h"
#include <cstdlib>

//constructor
Character::Character() {}

void Character::settype(char f) {
	if (f == 'b')
		type = 'b';
	if (f == 's')
		type = 's';
	if (f == 'g')
		type = 'g';
}

Character::~Character() {}