#include "Troll.h"
// Author: Ethan Fagan
// C00232277
// Date commenced: 04/10/18
// total time taken: 12 hours
// Date completed : 10/10/18


Troll::Troll()
{
	 m_healthPoints = 60;
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
	if (m_healthPoints <= 0)
	{
		m_isAlive = false;
		std::cout << "The troll slumps over dead" << std::endl;
	}
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

bool Troll::getLife()
{
	return m_isAlive;
}
