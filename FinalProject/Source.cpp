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

int morning_routine(double, int, Character);
int travel(double, int, Character);
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
	if (choice == 1) // 8 am
		countdown = 130;
	else if (choice == 2) // 9 am
		countdown = 70;
	else {
		cout << "Please restart and pick another time." << endl;
		return 0;
	}

	srand((unsigned)time(0));
	fate = 1 + (rand() % 5);

	switch (fate) {
	case 1: // wake up before alarm
		if (countdown == 130) {
			cout << "You woke up to your alarm." << endl;
			break;
		}
		if (countdown == 70) {
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
		if (countdown == 130) {
			countdown = countdown - 1;
		}
		if (countdown == 70) {
			countdown = countdown - 1;
		}
		cout << "Oh no! You slept through your alarm and lost an hour! You're feeling rushed!" << endl;
	}


	Character* player = new Character(countdown, distance, health, money);
	hour_minutes(countdown);
	cout << "This is your health: " << health << endl;

	// Start your morning routine
	choice = 0;
	while (choice != 4) {
		choice = morning_routine(countdown, health, *player);
	}

	// Leave the house, making your way downtown
	choice = 0;
	while (choice != 1  || choice != 2)  {
		choice = travel(countdown, health, *player);
	}

	// Make it to Starbucks

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

	switch (int(c)) {
	case 1: {
		Dressed player(c);
		c = player.reducetime();
		updatetime(c, player);
		break;
	}
	case 2: {
		Food player(c, h);
		c = player.reducetime('b');
		h = player.changehealth('b');
		updatetime(c, player);
		updatehealth(h, player);
		break;
	}
	case 3: {
		PackBag player(c);
		c = player.reducetime();
		updatetime(c, player);
		break; 
	}
	default:
		cout << "	You didn't select one of the given options." << endl;
	}
	return c;
}

int travel(double c, int h, Character p)
{
	cout << "Now that you made it out of the house, the first leg of your journey is to College Ave. How will you get there?" << endl;
	cout << "   1. Walk" << endl;
	cout << "   2. Run" << endl;
	cin >> c;

	switch (int(c)) {
	case 1: {
		Walk player(c, h);
		c = player.reducetime();
		h = player.changehealth();
		updatetime(c, player);
		updatehealth(h, player);
		break;
	}
	case 2: {
		Run player(c, h);
		c = player.reducetime();
		h = player.changehealth();
		updatetime(c, player);
		updatehealth(h, player);
		break;
	}
	default:
		cout << "	You didn't select one of the given options." << endl;
	}
	return c;
}

int travel(double c, int h, Character p)
{
	cout << "As you're making your way downtown, the smell of freshly-brewed, over-roasted coffe wafts through the air. Do you want to stop at Starbucks for a pick-me-up before your exam?" << endl;
	cout << "   1. Yes" << endl;
	cout << "   2. No" << endl;
	cin >> c;

	switch (int(c)) {
	case 1: {
		Food player(c, h);
		c = player.reducetime('s');
		h = player.changehealth('s');
		updatetime(c, player);
		updatehealth(h, player);
		break;
	}
	case 2: {
		Run player(c, h);
		c = player.reducetime();
		h = player.changehealth();
		updatetime(c, player);
		updatehealth(h, player);
		break;
	}
	default:
		cout << "	You didn't select one of the given options." << endl;
	}
	return c;
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