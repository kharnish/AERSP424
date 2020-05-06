#pragma once
#ifndef FOOD_H
#define FOOD_H
#include "Character.h"

class Food : public Character {

public:
	Food();
	double reducetime(double); //no longer takes an input, the character object has a settype memberfunction that changes the type (previousy char f) based on the set input
	int changehealth(int);	   //^^look at Food.cpp for example
	int changemoney(int);
};
#endif