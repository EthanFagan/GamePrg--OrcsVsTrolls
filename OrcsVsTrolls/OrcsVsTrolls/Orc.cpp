#include "Orc.h"

Orc::Orc()
{
	m_healthPoints = 100;
	m_magicPoints = 100;
	m_strength = 16;
	m_defence = 16;
	m_intelligence = 10;
	m_isAlive = true;
}

void Orc::attack()
{

}

void Orc::defend()
{

}

void Orc::spell()
{

}

void Orc::damaged()
{
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
