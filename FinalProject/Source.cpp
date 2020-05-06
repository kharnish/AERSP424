/*
Madeline Mayer
Kelly Harnish

AERSP 424
Final Project
5/6/2020

The Penn State Finals Trail
*/

#include <iostream>
#include <ios>
#include <cstdlib>
#include <stdio.h>
#include <stdlib.h>
#include <ctime>
#include <vector>
#include <fstream>
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
void updatestats(double, double, int, int);													 //changed and put all updates in one function (at the cost of all the functions needed all the inputs)
int checktimedistancehealth(char&, double&, double&, int&);
void playagainloop(int&);
void deathcertificate(double, double, int, int, int);

int main() {

	int finalanswer = 0;
	int i = 1;
	while (finalanswer != 2)
	{
		finalanswer = 0;
		int choice = 0;
		double countdown = 0.;
		double distance = 1.;
		int health = 50;
		int money = 20;
		char text = 'z'; //this is for the type (char f), comment about it in Food.h
		char check = 'z';


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
		while (choice != 1 && choice != 2)
		{
			cout << "Please pick another answer." << endl;
			cin >> choice;
		}

		if (choice == 1) // 8 am
			countdown = 130;
		else if (choice == 2) // 9 am
			countdown = 70;
		else
		{
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
		check = 'z';
		while (choice != 4)
		{
			morning_routine(choice, countdown, distance, health, money, ptrD, ptrF, ptrP); //notice the notation with the pointers
			finalanswer = checktimedistancehealth(check, countdown, distance, health);	//determines if player has succedded or failed
			if ((check == 'F') || (check == 'FF') || (check == 'P'))
			{
				deathcertificate(countdown, distance, health, money, i);
				if (finalanswer == 1)	//final answer is if the player wants to play the game again or not
					break;
				if (finalanswer == 2)
					return 0; //exits the program
			}
			updatestats(countdown, distance, health, money);							   //outputs stats to screen
		}

		// Leave the house, making your way downtown walking fast, faces pass, and you're homebound (dundundundundundundun)
		choice = 0;
		check = 'z';					   //vv this and vv this should be changed
		while ((finalanswer != 1) && (choice != 1) && (choice != 2)) //if they gave a final answer, then the while loop at the very beginning needs to be restarted
		{
			travel1(choice, countdown, distance, health, money, ptrW, ptrR);				//therefore, all these little nested loops need to be skipped over
			finalanswer = checktimedistancehealth(check, countdown, distance, health);
			if ((check == 'F') || (check == 'FF') || (check == 'P'))
			{
				deathcertificate(countdown, distance, health, money, i);
				if (finalanswer == 1)
					break;
				if (finalanswer == 2)
					return 0; //exits the program
			}
			updatestats(countdown, distance, health, money);
		}
		// Make it to Starbucks
		i++;
	}
	return 0;
}

int alarm(double c)
{
	int fate = 0;
	srand((unsigned)time(0));
	fate = 1 + (rand() % 5);

	switch (fate)
	{
	case 1: // wake up before alarm
		if (c == 130)
		{
			cout << "You woke up to your alarm." << endl;
			break;
		}
		if (c == 70)
		{
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
		if (c == 130)
		{
			c = c - 60;
		}
		if (c == 70)
		{
			c = c - 60;
		}
		cout << "Oh no! You slept through your alarm and lost an hour! You're feeling rushed!" << endl;
	}
	return c;
}

int morning_routine(int& choice, double& c, double& d, int& h, int& m, Character* dress, Character* eat, Character* pack) //notice the notation with the pointers
{

	dress->settime(c);		//I haven't found a better way to do this....so here's what i've been doing
	dress->setdistance(d);	//the derived objects don't use any initialization, and I couldn't figure out how to initalize them
	dress->sethealth(h);	//becuase i don't want to make setters and getters for every object, i decided just to use character
	dress->setmoney(m);		//this only needs to be done once, and you can use whatever object

	if (c <= 20)
	{
		cout << "You're cutting it close!" << endl;
	}
	cout << "What do you do?" << endl;
	cout << "	1. Get changed" << endl;
	cout << "	2. Eat breakfast" << endl;
	cout << "	3. Pack backpack" << endl;
	cout << "	4. Leave apartment" << endl;
	if (c <= 20)
	{
		cout << "	5. Sprint straight to Forum" << endl;
	}
	cin >> choice;

	switch (choice)
	{
	case 1:
	{
		c = dress->reducetime(c);
		break;
	}
	case 2:
	{
		eat->settype('b');		//comment on this in Food.h / Food.cpp
		c = eat->reducetime(c);	//changed member functions to take an input....this helped with the setting stuff
		h = eat->changehealth(h);
		break;
	}
	case 3:
	{
		c = pack->reducetime(c);
		break; 
	}
	case 4:
		break;
	case 5://player sprinted to Forum
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
		d = walk->reducedistance(d);
		h = run->changehealth(h);
		break;
	}
	default:
		cout << "	You didn't select one of the given options." << endl;
	}
	return 0;
}

int travel2(int& choice, double& c, double& d, int& h, int& m, Character* walk, Character* run)
{

	cout << "As you're making your way downtown, the smell of freshly-brewed, over-roasted coffee wafts through the air.\nDo you want to stop at Starbucks for a pick-me-up before your exam?" << endl;
	cout << "   1. Yes" << endl;
	cout << "   2. No" << endl;
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
		d = walk->reducedistance(d);
		h = run->changehealth(h);
		break;
	}
	default:
		cout << "	You didn't select one of the given options." << endl;
	}
	return 0;
}

void updatestats(double c, double d, int h, int m)
{
	cout << "\nYour stats:" << endl;
	cout << "	Time until exam: " << c << " minutes" << endl;
	cout << "	Distance from Forum: " << d << " mile" << endl;
	cout << "	Health: " << h << endl;
	cout << "	Money in your pocket: $" << m << "\n" << endl;
}

int checktimedistancehealth(char& check, double& c, double& d, int& h)
{
	int ans = 0;
	if (c <= 0)
	{
		c = 0;
		check = 'F'; //fail
		cout << "Oh no! You didn't make it to the exam on time!\nYou're going to have to retake the class!" << endl;
		playagainloop(ans);
	}
	if (d <= 0)
	{
		
		d = 0;
		check = 'P'; //success
		if (c > 5)
		{
			cout << "Congrats! You got to the exam on time. Good luck on your final exam!" << endl;
			playagainloop(ans);
		}
		if (c <= 5)
		{
			cout << "Phew you're beat but you made it just in time. Good luck on your final exam!" << endl;
			playagainloop(ans);
		}
	}
	if (h <= 0)
	{
		h = 0;
		int hope = 0;
		check = 'FF'; //fail but you also died
		cout << "Oh no! You passed out before you could make it!\nDo you get a doctor's note to take the conflict?" << endl;
		cout << "	1. Yes" << endl;
		cout << "	2. No" << endl;
		cin >> hope;

		if (hope == 1)
		{
			int fate = 0;
			srand((unsigned)time(0));
			fate = 1 + (rand() % 2);

			switch (fate)
			{
			case 1:
				cout << "You're lucky! Your professor accepts the doctor's note.\nYou get to take the make-up exam." << endl;
				playagainloop(ans);
				check = 'P';
				break;
			case 2:
				cout << "'Tough luck!' says your professor. You fail the exam. :~(" << endl;
				playagainloop(ans);
				break;
			}
		}
		if (hope == 2)
		{
			cout << "Well shucks. Better luck next semester!" << endl;
			playagainloop(ans);
		}
	}
	return ans;
}

void playagainloop(int& finalans)
{
	cout << "\nWould you like to play again?" << endl;
	cout << "	1. Yes" << endl;
	cout << "	2. No" << endl;
	cin >> finalans;
	while (finalans != 1 && finalans != 2)
	{
		cout << "Please pick another answer." << endl;
		cin >> finalans;
	}
	if (finalans == 1)
		cout << "Good luck..." << endl;
}

void deathcertificate(double c, double d, int h, int m, int i) //the i lets the program know if this was the first game run, puts header
{
	ofstream certificate("DeathCertificate.txt", ios_base::app | ios_base::out);
	
	if (i == 1 && certificate.is_open())
	{
		certificate << "~  T h e  P e n n  S t a t e  T r a i l ~" << endl;
		string str1("Score");
		string str2("Time (min)");
		string str3("Distance (mi)");
		string str4("Health");
		string str5("Money ($)");
		certificate << "		" << str1 << "		" << str2 << "	" << str3 << "	" << str4 << "		" << str5 << endl;
	}
	
	string name = "z";
	cout << "\nEnter your nickname (max 7 characters): ";
	cin >> name;
	string str6(name);
	if (str6.length() > 7)
		str6.erase(7);
	cout << endl;
	int score = 22 * c + 34 * d + 15 * h + 9 * m;
	float final[5] = { score, c, d, h, m };;
	
	vector< float > vecDC;	//vector for final scores
	vecDC.insert(vecDC.begin(), final, final + 5); //inserts array into vector

	if (certificate.is_open())
	{
		certificate << str6 << "	";
		for (int i = 0; i < 5; i++)
		{
			certificate << "	" << vecDC[i] << "	";
		}
		certificate << endl;
		certificate.close();
	}
	else
		cout << "Unable to open file";
}
