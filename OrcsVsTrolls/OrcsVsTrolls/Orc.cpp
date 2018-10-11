#include "Orc.h"

Orc::Orc()
{
	m_healthPoints = 100;
	m_magicPoints = 100;
	m_strength = 16;
	m_defence = 2;
	m_intelligence = 16;
	m_isAlive = true;
}

int Orc::attack()
{
	return (m_strength);
}

void Orc::defend()
{
	m_defence = m_defence + m_defence;
}

int Orc::spell()
{
	m_magicPoints -= 20;

	return (m_intelligence * 3);

}

void Orc::damaged(int t_damage)
{
	m_healthPoints -= (t_damage / m_defence);
}

int Orc::getHealth()
{
	return m_healthPoints;
}

int Orc::getStrength()
{
	return m_strength;
}

int Orc::getDefence()
{
	return m_defence;
}

int Orc::getIntelligence()
{
	return m_intelligence;
}

int Orc::getMagic()
{
	return 0;
}
