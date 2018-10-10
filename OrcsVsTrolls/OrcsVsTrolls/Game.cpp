#include "Game.h"
#include <iostream>

Game::Game()
{
	for (int i = 0; i < 4; i++)
	{
		orcs[i] = new Orc;
	}

	for (int i = 0; i < 4; i++)
	{
		trolls[i] = new Troll;
	}
}

void Game::run()
{
	
	introduction();
	partyOrganization();
	std::cout << "THE SUN RISES.. AND WITH IT COME THE TROLLS" << std::endl;
	while (m_gameOver == false)
	{
		partyOrganization();
		combat();
		if (orcs[0]->getHealth() == 0 && orcs[1]->getHealth() == 0 && orcs[2]->getHealth() == 0 && orcs[3]->getHealth() == 0)
		{
			m_gameOver = true;
		}
		if (trolls[0]->getHealth() == 0 && trolls[1]->getHealth() == 0 && trolls[2]->getHealth() == 0 && trolls[3]->getHealth() == 0)
		{
			m_gameOver = true;
		}
	}
	if (orcs[0]->getHealth() == 0 && orcs[1]->getHealth() == 0 && orcs[2]->getHealth() == 0 && orcs[3]->getHealth() == 0)
	{

	}
	endGame();
}

void Game::introduction()
{
	std::cout << "[][][][][][][][][][][[[][][][][][][][][][][][][][][][][][][][][][][][][][][][][]" << std::endl;
	std::cout << " Night falls, as the moonlight radiates over your camp.\n You lament the scenario you've now found yourself in,\n You lie tied up against a tree, as 4 Orcs bicker over your fate"<< std::endl;
	std::cout << " Among their brazen arguing, you overhear talk of a group of local Trolls who've been hassling the Orc group as of late\n Sensing an oppertunity to bargain for escape you raise your voice" << std::endl;
	std::cout << " You quickly strike a deal with the Orc leader,\n You help them work together to defeat the trolls when they return at sunrise,\n and you go free" << std::endl;
	std::cout << "[][][][][][][][][][][][][][][][][][][][][][][][]][][][][][][][][][][][][]][][][]" << std::endl;
}

void Game::combat()
{
	
}
	

void Game::partyOrganization()
{
	for (int i = 0; i < 4; i++)
	{
		std::cout << "Orc " << i << " has " << orcs[i]->getHealth() << " HP remaining" << std::endl;
		std::cout << "Orc " << i << " has " << orcs[i]->getMagic() << " MP remaining" << std::endl;
	}

	for (int i = 0; i < 4; i++)
	{
		std::cout << "Troll " << i << " has " << trolls[i]->getHealth() << " HP remaining" << std::endl;
	}
}

void Game::endGame()
{
	std::cout << "You won, sick" << std::endl;
}


