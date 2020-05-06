#pragma once
#ifndef BUS_H
#define BUS_H
#include "Character.h"

class Bus : public Character {

public:
	Bus();
	double reducetime(double);
	double reducedistance(double);
};
#endif