#pragma once
#ifndef FOOD_H
#define FOOD_H
#include "Character.h"

class Food : public Character {

public:
	Food(double, int);
	double reducetime(char);
	int changehealth(char);
};
#endif