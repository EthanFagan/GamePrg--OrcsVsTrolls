#pragma once
#include <iostream>
#include "Character.h"

class Orc : public Character {
public:
	Orc();
	void attack();
	void defend();
	void spell();
    void damaged();
	int getHealth();
	int getStrength();
	int getDefence();
	int getIntelligence();
	int getMagic();
protected:
	std::string m_name = ("");
	int m_healthPoints;
	int m_magicPoints;
	int m_strength;
	int m_defence;
	int m_intelligence;
	bool m_isAlive;
};