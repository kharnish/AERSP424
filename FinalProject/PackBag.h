#pragma once
#ifndef PACKBAG_H
#define PACKBAG_H
#include "Character.h"

class PackBag : public Character {

public:
	PackBag(double);
	double reducetime();
};
#endif