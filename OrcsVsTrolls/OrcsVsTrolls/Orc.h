#pragma once
#include <iostream>
#include "Character.h"

class Orc : public Character {
public:
	Orc();
	int attack(); // returns the Orcs base damage
	void defend();// doubles Orcs defence
	int spell();// returns trhe Orcs magic damage
    void damaged(int t_damage);// deals damage to Orc based on damage recieved
	int getHealth();// returns Orc current hp
	int getStrength();// returns Orcs current strength
	int getDefence();// returns Orcs current defence
	int getIntelligence();// returns Orcs current intelligence
	int getMagic();// returns Orcs current mp
	bool getLife();// returns whether Orc is alive
protected:
	
	int m_healthPoints;
	int m_magicPoints;
	int m_strength;
	int m_defence;
	int m_intelligence;
	bool m_isAlive;
};