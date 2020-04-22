#include "character.h"

Character::Character() {
	isAlive = true;
	health = 100;
}

int Character::getHealth() {
	return health;
}
void Character::changeHealth(int change) {
	if (isAlive == true) {
		if (health + change > 100) {
			health = health;
		}
		else if (health + change < 0) {
			isAlive = false;
		}
	}
}
bool Character::getAlive() { 
	return isAlive;
}
