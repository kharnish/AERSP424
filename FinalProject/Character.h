#pragma once
#ifndef CHARACTER_H
#define CHARACTER_H
class Character
{
public:
	//constructor
	Character(double);
	Character(double, int);
	Character(double, double, int, int);
	~Character();

	//setters and getters
	//void settime(double t) { time = t; }					//setters typically have a parameter, no return
	//void setdistance(float d) { distance = d; }
	//void sethealth(int h) { health = h; }
	//void setmoney(int m) { money = m; }
	double gettime() { return time; }					//getters typically have no parameters, return a value
	double getdistance() { return distance; }
	int gethealth() { return health; }
	int getmoney() { return money; }

	//member functions
	virtual double reducetime() { return 0; }
	virtual double reducedistance() { return 0; }
	virtual int changehealth() { return 0; }
	virtual int changemoney() { return 0; }

	//data members
	double time;
	double distance;
	int health;
	int money;
};
#endif