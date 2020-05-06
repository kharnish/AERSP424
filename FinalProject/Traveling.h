#pragma once
#ifndef TRAVELING_H
#define TRAVELING_H
#include "Character.h"
#include <iostream>
using namespace std;

int travel1(int& choice, double& c, double& d, int& h, int& m, Character* walk, Character* run)
{
	cout << "\nNow that you made it out of the house, the first leg of your journey is to College Ave. How will you get there?" << endl;
	cout << "	1. Walk" << endl;
	cout << "	2. Run" << endl;
	if (c <= 20)
	{
		cout << "	3. Sprint straight to Forum" << endl;
	}
	cin >> choice;

	switch (choice)
	{
	case 1:
	{
		c = walk->reducetime(c);
		d = walk->reducedistance(d);
		h = walk->changehealth(h);
		break;
	}
	case 2:
	{
		c = run->reducetime(c);
		d = run->reducedistance(d);
		h = run->changehealth(h);
		break;
	}
	case 3://player sprinted to Forum
	{
		c = 1;
		d = 0;
		h = 1;
		break;
	}
	default:
		cout << "	You didn't select one of the given options." << endl;
	}
	return 0;
}

int travel2(int& choice, double& c, double& d, int& h, int& m, Character* walk, Character* run, Character* eat)
{
	if (c <= 20)
	{
		cout << "You're cutting it close!" << endl;
	}
	cout << "As you're making your way downtown, the smell of freshly-brewed, over-roasted coffee wafts through the air.\nDo you want to stop at Starbucks for a pick-me-up before your exam?" << endl;
	cout << "   1. Yes" << endl;
	cout << "   2. No" << endl;
	cin >> choice;

	switch (choice)
	{
	case 1:
	{
		eat->settype('s');
		c = eat->reducetime(c);
		h = eat->changehealth(h);
		m = eat->changemoney(m);

		cout << "You've just got your coffee, do you walk to run to the bus stop?" << endl;
		cout << "   1. Walk" << endl;
		cout << "   2. Run" << endl;
		if (c <= 20)
		{
			cout << "	3. Sprint straight to Forum" << endl;
		}
		cin >> choice;

		switch (choice)
		{
		case 1:	//walk out of starbz
			c = walk->reducetime(c);
			d = walk->reducedistance(d);
			h = walk->changehealth(h);
			break;
		case 2:  //run out of starbz
		{
			c = run->reducetime(c);
			d = run->reducedistance(d);
			h = run->changehealth(h);
			break;
		}
		case 3://player sprinted to Forum
		{
			c = 1;
			d = 0;
			h = 1;
			break;
		}
		default:
			cout << "	You didn't select one of the given options." << endl;
		}
		break;
	}
	case 2:
	{
		cout << "You check your watch and note the time, do you walk to run to the bus stop?" << endl;
		cout << "   1. Walk" << endl;
		cout << "   2. Run" << endl;
		if (c <= 20)
		{
			cout << "	3. Sprint straight to Forum" << endl;
		}
		cin >> choice;

		switch (choice)
		{
		case 1:	//walk to bus stop
			c = walk->reducetime(c);
			d = walk->reducedistance(d);
			h = walk->changehealth(h);
			break;
		case 2:  //run to bus stop
		{
			c = run->reducetime(c);
			d = run->reducedistance(d);
			h = run->changehealth(h);
			break;
		}
		case 3://player sprinted to Forum
		{
			c = 1;
			d = 0;
			h = 1;
			break;
		}
		default:
			cout << "	You didn't select one of the given options." << endl;
		}
		break;
	}
	default:
		cout << "	You didn't select one of the given options." << endl;
	}
	return 0;
}

int travel3(int& choice, double& c, double& d, int& h, int& m, Character* walk, Character* run, Character* bus) {
	if (c <= 20)
	{
		cout << "You're cutting it close!" << endl;
	}
	cout << "You've made it to the bus stop. Do you take the bus or keep going?" << endl;
	cout << "	1. Take Whoop" << endl;
	cout << "	2. Take Bloop" << endl;
	cout << "	3. Keep going" << endl;
	if (c <= 20)
	{
		cout << "	4. Sprint straight to Forum" << endl;
	}
	cin >> choice;

	switch (choice)
	{
	case 1:
	{
		bus->settype('W');
		bus->reducetime(c);
		bus->reducedistance(d);
		break;
	}
	case 2:
	{
		bus->settype('B');
		bus->reducetime(c);
		bus->reducedistance(d);
		break;
	}
	case 3:
	{
		break;
	}
	case 4: //straight to Forum
	{
		c = 1;
		d = 0;
		h = 1;
		break;
	}
	default:
		cout << "	You didn't select one of the given options." << endl;
	}
	return 0;
}

#endif