#pragma once
#include <iostream>

class Character {
public:
	virtual int attack();
	virtual void defend();
	virtual int spell(); //pure virtual function
	virtual void damaged(int t_damage);
	virtual int getHealth();
	virtual int getStrength();
	virtual int getDefence();
	virtual int getIntelligence();
	virtual int getMagic();
protected:
	int healthPoints = 0;
	int magicPoints = 0;
	int strength = 0;
	int defence = 0;
	int intelligence = 0;
	bool isAlive = true;
};



