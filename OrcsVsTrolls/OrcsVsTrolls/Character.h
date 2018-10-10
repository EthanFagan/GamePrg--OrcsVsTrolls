#pragma once
#include <iostream>
#include "Character.h"

class Character {
public:
	//virtual void attack();
	//virtual void defend();
	//virtual void spell() = 0; //pure virtual function

protected:
	int healthPoints;
	int magicPoints;
	int strength;
	int agility;
	int intelligence;
};

class Orc : public Character {
public:
	/*void barrelRoll();
	void walk();
	void fly();
*/

};

class Troll : public Character {
public:
 void fly() { std::cout << "Average Dooper is flapping and flying" << std::endl; }
};
