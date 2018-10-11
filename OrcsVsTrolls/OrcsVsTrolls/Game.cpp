#include "Game.h"
#include <iostream>
#include <time.h>

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
	srand((unsigned)time(NULL));

	introduction();
	
	std::cout << "THE SUN RISES.. AND WITH IT COMES THE TROLLS" << std::endl;
	while (m_gameOver == false)
	{
		partyOrganization();
		combat();
		if (orcs[0]->getHealth() <= 0 && orcs[1]->getHealth() <= 0 && orcs[2]->getHealth() <= 0 && orcs[3]->getHealth() <= 0)
		{
			m_gameOver = true;
		}
		if (trolls[0]->getHealth() <= 0 && trolls[1]->getHealth() <= 0 && trolls[2]->getHealth() <= 0 && trolls[3]->getHealth() <= 0)
		{
			m_gameOver = true;
		}
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
	for (int i = 0; i < 4; i++)
	{
		int playerChoice = -1;
		while(playerChoice != 1 && playerChoice != 2 && playerChoice !=3)
		{
			std::cout << "What will Orc " << i + 1 << " do?\n" << " 1 = Attack\n 2 = Defend\n 3 = cast magic " << std::endl;
			std::cin >> playerChoice;
		}
		if (playerChoice == 1)
		{
			int enemyChoice = -1;
			std::cout << "which troll will he attack?" << std::endl;
			std::cin >> enemyChoice;
			int damage = orcs[i]->attack();
			trolls[enemyChoice-1]->damaged(damage);
			std::cout << "Troll " << enemyChoice << " takes " << damage << " points of damage" << std::endl;
		}
	    if (playerChoice == 2)
		{
			orcs[i]->defend();
			std::cout << "Orc " << i + 1 << "s defence is now doubled until the end of the turn" << std::endl;
		}
		if (playerChoice == 3)
		{
			int enemyChoice = -1;
			std::cout << "which troll will he attack?" << std::endl;
			std::cin >> enemyChoice;
			int damage = orcs[i]->spell();
			trolls[enemyChoice-1]->damaged(damage);
			std::cout << "Troll " << enemyChoice << " takes " << damage << " points of damage" << std::endl;
		}
	}
}

void Game::enemyCombat()
{
	for (int i = 0; i < 4; i++)
	{
		int target = rand() % 4 + 1;
		int damage = trolls[i]->attack();
		
		orcs[target-1]->damaged(damage);

		std::cout << "Orc " << target << " takes " << damage << " points of damage" << std::endl;
	}
}
	

void Game::partyOrganization()
{
	for (int i = 0; i < 4; i++)
	{
		std::cout << "Orc " << i +1 << " has " << orcs[i]->getHealth() << " HP remaining" << std::endl;
		std::cout << "Orc " << i +1 << " has " << orcs[i]->getMagic() << " MP remaining" << std::endl;
	}

	for (int i = 0; i < 4; i++)
	{
		std::cout << "Troll " << i + 1 << " has " << trolls[i]->getHealth() << " HP remaining" << std::endl;
	}
}

void Game::endGame()
{

	if (orcs[0]->getHealth() == 0 && orcs[1]->getHealth() == 0 && orcs[2]->getHealth() == 0 && orcs[3]->getHealth() == 0)
	{
		std::cout << "everyone died, the end" << std::endl;
	}
	if (trolls[0]->getHealth() == 0 && trolls[1]->getHealth() == 0 && trolls[2]->getHealth() == 0 && trolls[3]->getHealth() == 0)
	{
		std::cout << "You won, sick" << std::endl;
	}
	
}


