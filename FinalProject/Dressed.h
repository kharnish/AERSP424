#pragma once
#ifndef DRESSED_H
#define DRESSED_H
#include "Character.h"

class Dressed : public Character {

public:
	Dressed();
	double reducetime(double);
};
#endif