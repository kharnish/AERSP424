#pragma once
#ifndef RUN_H
#define RUN_H
#include "Character.h"

class Run : public Character {

public:
	Run(double, int);
	double reducetime();
	int changehealth();
};
#endif