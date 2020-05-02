#pragma once
#ifndef WALK_H
#define WALK_H
#include "Character.h"

class Walk : public Character {

public:
	Walk();
	double reducetime(double);
	double reducedistance(double);
	int changehealth(int);
};
#endif