#pragma once
#include <iostream>

class Character {
public:
	virtual int attack();// returns the characters base damage
	virtual void defend();// doubles characters defence
	virtual int spell(); // returns trhe characters magic damage
	virtual void damaged(int t_damage);// deals damage to character based on damage recieved
	virtual int getHealth();// returns characters currente hp
	virtual int getStrength();// returns characters current strength
	virtual int getDefence();// returns characters current defence
	virtual int getIntelligence();// returns characters current intelligence
	virtual int getMagic();// returns characters current mp
	virtual bool getLife();// returns whether character is alive
protected:
	int healthPoints = 0;//
	int magicPoints = 0;//
	int strength = 0;//
	int defence = 0;//
	int intelligence = 0;//
	bool isAlive = true;//
};



