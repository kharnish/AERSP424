#pragma once
#ifndef CHARACTER_H
#define CHARACTER_H
class Character
{
public:
	//constructor
	Character();
	~Character();

	//setters and getters
	void settime(double t) { time = t; }					//setters typically have a parameter, no return
	void setdistance(float d) { distance = d; }
	void sethealth(int h) { health = h; }
	void setmoney(int m) { money = m; }
	void settype(char f);
	double gettime() { return time; }						//getters typically have no parameters, return a value
	double getdistance() { return distance; }
	int gethealth() { return health; }
	int getmoney() { return money; }

	//member functions
	virtual double reducetime(double) { return 0; }
	virtual double reducedistance(double) { return 0; }
	virtual int changehealth(int) { return 0; }
	virtual int changemoney(int) { return 0; }

	//data members
	double time;
	double distance;
	int health;
	int money;
	char type;
};
#endif