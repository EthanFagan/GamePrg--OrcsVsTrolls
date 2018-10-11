#include "Troll.h"

Troll::Troll()
{
	 m_healthPoints = 30;
	 m_magicPoints = 0;
	 m_strength = 10;
	 m_defence = 2;
	 m_intelligence = 8;
	 m_isAlive = true;
}

int Troll::attack()
{
	return 0;
}

void Troll::damaged(int t_damage)
{
	m_healthPoints -= (t_damage / m_defence);
}

int Troll::getHealth()
{
	return m_healthPoints;
}

int Troll::getStrength()
{
	return m_strength;
}

int Troll::getDefence()
{
	return m_defence;
}

int Troll::getIntelligence()
{
	return m_intelligence;
}
