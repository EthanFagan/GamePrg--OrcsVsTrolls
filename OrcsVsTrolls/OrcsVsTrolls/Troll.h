#pragma once
#include <iostream>
#include "Character.h"

class Troll : public Character {
public:
	void attack();
	void damaged();
	int getHealth();
	int getStrength();
	int getDefence();
	int getIntelligence();

protected:
	
	int m_healthPoints;
	int m_magicPoints;
	int m_strength;
	int m_defence;
	int m_intelligence;
	bool m_isAlive;
};
