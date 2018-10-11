#pragma once
#include <iostream>
#include "Character.h"

class Troll : public Character {
public:
	Troll();
	int attack(); // returns the Trolls base damage
	void damaged(int t_damage);// deals damage to Troll based on damage recieved
	int getHealth();// returns Trolls current hp
	int getStrength();// returns Trolls current strength
	int getDefence();// returns Trolls current defence
	int getIntelligence();// returns Trolls current intelligence
	bool getLife();// returns whether Troll is alive

protected:
	
	int m_healthPoints;
	int m_magicPoints;
	int m_strength;
	int m_defence;
	int m_intelligence;
	bool m_isAlive;
};
