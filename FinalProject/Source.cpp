// Madeline Mayer & Kelly Harnish	AERSP 424		Final Project		5/6/2020

#include <iostream>
#include <cstdlib>
#include <stdio.h>
#include <stdlib.h>
#include <ctime>
#include "Character.h"
#include "Dressed.h"
#include "PackBag.h"
#include "Food.h"
using namespace std;

int morning_routine(double, int, Character);
void travel(double, int, Character);
void updatetime(double &, Character);
void updatehealth(int&, Character);
void hour_minutes(double&);

int main() {

	int choice = 0;
	double countdown = 0.;
	double distance = 1.;
	int health = 50;
	int money = 20;
	int fate = 0;

	cout << "You have a final exam at 10:10 am tomorrow morning in Forum, a mile walk from your apartment.\nYou're feeling prepared for the exam, and wish to get plenty of sleep.\nDo you set you're alarm for 8 or 9 am?" << endl;
	cout << "	1. 8 am" << endl;
	cout << "	2. 9 am" << endl;

	cin >> choice;
	if (choice == 1) //8 am
		countdown = 2.167;
	else if (choice == 2) //9 am
		countdown = 1.167;
	else {
		cout << "Please restart and pick another time." << endl;
		return 0;
	}

	srand((unsigned)time(0));
	fate = 1 + (rand() % 5);

	switch (fate) {
	case 1: //wake up before alarm
		if (countdown == 2.167) {
			cout << "You woke up to your alarm." << endl;
			break;
		}

		if (countdown == 1.167) {
			countdown = countdown + 1;
			cout << "Phew! You woke up an hour early. You have extra time." << endl;
			break;
		}
	case 2: //wake up on time
	case 3:
	case 4:
		cout << "You woke up to your alarm." << endl;
		break;
	case 5: //wake up late
		if (countdown == 2.167) {
			countdown = countdown - 1;
		}
		if (countdown == 1.167) {
			countdown = countdown - 1;
		}
		cout << "Oh no! You slept through your alarm and lost an hour! You're feeling rushed!" << endl;
	}


	Character* player = new Character(countdown, distance, health, money);
	hour_minutes(countdown);
	cout << "This is your health: " << health << endl;

	choice = 0;
	while (choice != 4) {
		choice = morning_routine(countdown, health, *player);
	}

	travel(countdown, health, *player);

	return 0;
}

int morning_routine(double c, int h, Character p)
{
	cout << "What do you do?" << endl;
	cout << "	1. Get changed" << endl;
	cout << "	2. Eat breakfast" << endl;
	cout << "	3. Pack backpack" << endl;
	cout << "	4. Leave apartment" << endl;
	cin >> c;

	if (c == 1) {
		Dressed player(c);
		c = player.reducetime();
		updatetime(c, player);
	}
	if (c == 2) {
		Food player(c, h);
		c = player.reducetime();
		h = player.changehealth();
		updatetime(c, player);
		updatehealth(h, player);
	}
	if (c == 3) {
		PackBag player(c);
		c = player.reducetime();
		updatetime(c, player);
	}
	return c;
}

void travel(double c, int h, Character p)
{
	cout << "Now that you made it out of the house, how do you want to get to Forum?" << endl;
	cout << "	1. Walk" << endl;
	cout << "	2. Run" << endl;
	cout << "	3. Take the bus" << endl;
	cout << "	4. Call an Uber" << endl;
	cin >> c;

	if (c == 1) {
		Dressed player(c);
		c = player.reducetime();
		updatetime(c, player);
		// woooo
	}
	if (c == 2) {
		Food player(c, h);
		c = player.reducetime();
		h = player.changehealth();
		updatetime(c, player);
		updatehealth(h, player);
	}
	if (c == 3) {
		PackBag player(c);
		c = player.reducetime();
		updatetime(c, player);
	}
}

void updatetime(double& c, Character p)
{
	p.gettime();
	hour_minutes(c);
}

void updatehealth(int& h, Character p)
{
	h = p.gethealth();
	cout << "This is your health: " << h << endl;
}

void hour_minutes(double& c)
{
	int seconds = c * 3600;
	int hours = seconds / 3600;
	int remainingseconds = seconds %= 3600;
	int minutes = remainingseconds / 60;

	cout << "You have " << hours << " hours and " << minutes << " minutes remianing until your exam.\n" << endl;
}