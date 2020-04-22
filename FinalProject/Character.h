#ifndef CHARACTER_H
#define CHARACTER_H

class Character {
	public: //member functions
		Character();
		int getHealth();
		void changeHealth(int);
		bool getAlive();

	private: //data members
		bool isAlive;
		int health;
};
#endif