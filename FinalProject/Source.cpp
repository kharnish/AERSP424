/*
Madeline Mayer
Kelly Harnish

AERSP 424
Final Project
5/6/2020

The Penn State Finals Trail
*/

#include <iostream>
#include <cstdlib>
#include <stdio.h>
#include <stdlib.h>
#include <ctime>
#include "Character.h"
#include "Dressed.h"
#include "PackBag.h"
#include "Food.h"
#include "Walk.h"
#include "Run.h"
using namespace std;

int alarm(double);
int morning_routine(int&, double&, double&, int&, int&, Character*, Character*, Character*); //brute force, kind of ugly but it works....includes all variables. includes the objects that can affect the function
int travel1(int&, double&, double&, int&, int&, Character*, Character*);					 //first int is choice. it wasn't returning choice, it was returning time for some reason and i didn't know/feel like fixing it
int travel2(int&,double&, double&, int&, int&, Character*, Character*);						 //i.e. morning routine has dressed, food, and backpack. travels only have walk and run rn.
void deathcertificate();																	 //mentioned in google doc, will be working on this saturday day
void updatestats(double&, double&, int&, int&, Character*);									 //changed and put all updates in one function (at the cost of all the functions needed all the inputs)

int main() {

	int choice = 0;
	double countdown = 0.;
	double distance = 1.;
	int health = 50;
	int money = 20;
	char text = 'z'; //this is for the type (char f), comment about it in Food.h


	Dressed aDressed;	//found out this is the proper way to do virtual functions...it's to use pointers to the base class
	Food aFood;
	PackBag aPackBag;
	Run aRun;
	Walk aWalk;
	Character* ptrD = &aDressed;
	Character* ptrF = &aFood;
	Character* ptrP = &aPackBag;
	Character* ptrR = &aRun;
	Character* ptrW = &aWalk;

	cout << "You have a final exam at 10:10 am tomorrow morning in Forum, a " << distance << " mile walk from your apartment.\nYou're feeling prepared for the exam, and wish to get plenty of sleep.\nDo you set you're alarm for 8 or 9 am?" << endl;
	cout << "	1. 8 am" << endl;
	cout << "	2. 9 am" << endl;

	cin >> choice;
	if (choice == 1) // 8 am
		countdown = 130;
	else if (choice == 2) // 9 am
		countdown = 70;
	else {
		cout << "Please restart and pick another time." << endl;
		return 0;
	}

	cout << "\nSleep well...\n" << endl;

	// Does your alarm go off?
	countdown = alarm(countdown); //moved to a funciton

	cout << "Your stats:" << endl;
	cout << "	Time until exam: " << countdown << " minutes" << endl;
	cout << "	Distance from Forum: " << distance << " mile" << endl;
	cout << "	Health: " << health << endl;
	cout << "	Money in your pocket: $" << money << "\n" << endl;

	// Start your morning routine
	choice = 0;
	while (choice != 4) {
		morning_routine(choice, countdown, distance, health, money, ptrD, ptrF, ptrP); //notice the notation with the pointers
	}

	// Leave the house, making your way downtown walking fast, faces past, and you're homebound (dundundundundundundun)
	choice = 0;
	while (choice != 1 || choice != 2)  {	//this should be changed to something else
		travel1(choice, countdown, distance, health, money, ptrW, ptrR);
	}

	// Make it to Starbucks

	return 0;
}

int alarm(double c)
{
	int fate = 0;
	srand((unsigned)time(0));
	fate = 1 + (rand() % 5);

	switch (fate) {
	case 1: // wake up before alarm
		if (c == 130) {
			cout << "You woke up to your alarm." << endl;
			break;
		}
		if (c == 70) {
			c = c + 30;
			cout << "Phew! You woke up early. You have extra time." << endl;
			break;
		}
	case 2: //wake up on time
	case 3:
	case 4:
		cout << "You woke up to your alarm." << endl;
		break;
	case 5: //wake up late
		if (c == 130) {
			c = c - 60;
		}
		if (c == 70) {
			c = c - 60;
		}
		cout << "Oh no! You slept through your alarm and lost an hour! You're feeling rushed!" << endl;
	}
	return c;
}

int morning_routine(int& choice, double& c, double& d, int& h, int& m, Character* dress, Character* eat, Character* pack) //notice the notation with the pointers
{

	dress->settime(c);									//I haven't found a better way to do this....so here's what i've been doing
	dress->setdistance(d);								//the derived objects don't use any initialization, and I couldn't figure out how to initalize them
	dress->sethealth(h);								//becuase i don't want to make setters and getters for every object, i decided just to use character
	dress->setmoney(m);									//this only needs to be done once at the beginning of each fucntion, and you can use whatever object

	cout << "What do you do?" << endl;
	cout << "	1. Get changed" << endl;
	cout << "	2. Eat breakfast" << endl;
	cout << "	3. Pack backpack" << endl;
	cout << "	4. Leave apartment" << endl;
	cin >> choice;

	switch (choice) {
	case 1: {
		c = dress->reducetime(c);
		if (c <= 0) {
			//ill be working on the death certificate stuff saturday day.....even though its 5:29 am saturday morning as I type this...
			return 0;
		}
		updatestats(c, d, h, m, dress); //notice the notation for this....it doesn't really matter the pointer because they all get and set the same
		break;
	}
	case 2: {
		eat->settype('b');	//comment on this in Food.h / Food.cpp
		c = eat->reducetime(c);	//changed member functions to take an input....this helped with the setting stuff
		h = eat->changehealth(h);
		updatestats(c, d, h, m, eat);
		break;
	}
	case 3: {
		c = pack->reducetime(c);
		updatestats(c, d, h, m, pack);
		break; 
	}
	case 4:
		break;
	default:
		cout << "	You didn't select one of the given options." << endl;
	}
	return 0;
}

int travel1(int& choice, double& c, double& d, int& h, int& m, Character* walk, Character* run)
{
	
	walk->settime(c);
	walk->setdistance(d);
	walk->sethealth(h);
	walk->setmoney(m);

	cout << "\nNow that you made it out of the house, the first leg of your journey is to College Ave. How will you get there?" << endl;
	cout << "   1. Walk" << endl;
	cout << "   2. Run" << endl;
	cin >> choice;

	switch (choice) {
	case 1: {
		c = walk->reducetime(c);
		d = walk->reducedistance(d);
		h = walk->changehealth(h);
		updatestats(c, d, h, m, walk);
		break;
	}
	case 2: {
		c = run->reducetime(c);
		d = walk->reducedistance(d);
		h = run->changehealth(h);
		updatestats(c, d, h, m, run);
		break;
	}
	default:
		cout << "	You didn't select one of the given options." << endl;
	}
	return 0;
}

int travel2(int& choice, double& c, double& d, int& h, int& m, Character* walk, Character* run)
{
	
	walk->settime(c);
	walk->setdistance(d);
	walk->sethealth(h);
	walk->setmoney(m);

	cout << "As you're making your way downtown, the smell of freshly-brewed, over-roasted coffee wafts through the air. Do you want to stop at Starbucks for a pick-me-up before your exam?" << endl;
	cout << "   1. Yes" << endl;
	cout << "   2. No" << endl;
	cin >> choice;

	switch (choice) {
	case 1: {
		c = walk->reducetime(c);
		d = walk->reducedistance(d);
		h = walk->changehealth(h);
		updatestats(c, d, h, m, walk);
		break;
	}
	case 2: {
		c = run->reducetime(c);
		d = walk->reducedistance(d);
		h = run->changehealth(h);
		updatestats(c, d, h, m, run);
		break;
	}
	default:
		cout << "	You didn't select one of the given options." << endl;
	}
	return 0;
}

void updatestats(double& c, double& d, int& h, int& m, Character* p)
{

	p->settime(c);
	p->setdistance(d);
	p->sethealth(h);
	p->setmoney(m);

	c = p->gettime();
	d = p->getdistance();
	h = p->gethealth();
	m = p->getmoney();

	cout << "\nYour stats:" << endl;
	cout << "	Time until exam: " << c << " minutes" << endl;
	cout << "	Distance from Forum: " << d << " mile" << endl;
	cout << "	Health: " << h << endl;
	cout << "	Money in your pocket: $" << m << "\n" << endl;
	
}