#pragma once
#ifndef WALK_H
#define WALK_H
#include "Character.h"

class Walk : public Character {

public:
	Walk(double, int);
	double reducetime();
	int changehealth();
};
#endif