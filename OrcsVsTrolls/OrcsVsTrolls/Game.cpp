#include "Game.h"
#include <iostream>
#include <time.h>
// Author: Ethan Fagan
// C00232277
// Date commenced: 04/10/18
// total time taken: 12 hours
// Date completed : 10/10/18


Game::Game()
{
	// assigning the sublclasses for orcs and trolls
	for (int i = 0; i < 4; i++)
	{
		orcs[i] = new Orc;
	}

	for (int i = 0; i < 4; i++)
	{
		trolls[i] = new Troll;
	}
	//----------------------------------------------------
}

void Game::run()
{
	// setting up RNG
	srand((unsigned)time(NULL));

	// outputting the intro before the game starts
	introduction();
	
	std::cout << "THE SUN RISES.. AND WITH IT COMES THE TROLLS" << std::endl;
	//---------------------------------------------------------------------------
	//                       CORE GAME LOOP
	//---------------------------------------------------------------------------
	while (m_gameOver == false)
	{
		// outputting the battle status at the beginning of each loop
		partyOrganization();

		// The player takes their turn
		combat();

		//-----------------------------------------------Checks for a game over-------------------------------------------\\ 
		if (orcs[0]->getHealth() <= 0 && orcs[1]->getHealth() <= 0 && orcs[2]->getHealth() <= 0 && orcs[3]->getHealth() <= 0)
		{
			m_gameOver = true;
		}
		if (trolls[0]->getHealth() <= 0 && trolls[1]->getHealth() <= 0 && trolls[2]->getHealth() <= 0 && trolls[3]->getHealth() <= 0)
		{
			m_gameOver = true;
		}

		// enemy units take their turns
		enemyCombat();

		//-----------------------------------------------Checks for a game over-------------------------------------------\\ 
		if (orcs[0]->getHealth() <= 0 && orcs[1]->getHealth() <= 0 && orcs[2]->getHealth() <= 0 && orcs[3]->getHealth() <= 0)
		{
			m_gameOver = true;
		}
		if (trolls[0]->getHealth() <= 0 && trolls[1]->getHealth() <= 0 && trolls[2]->getHealth() <= 0 && trolls[3]->getHealth() <= 0)
		{
			m_gameOver = true;
		}
	}
	
	// ending the game
	endGame();
}

void Game::introduction()
{
	// intro message
	std::cout << "[][][][][][][][][][][][][][][][][][][][][][][][][][][][][][][][][][][][][][][][]" << std::endl;
	std::cout << " Night falls, as the moonlight radiates over your camp.\n You lament the scenario you've now found yourself in,\n You lie tied up against a tree, as 4 Orcs bicker over your fate"<< std::endl;
	std::cout << " Among their brazen arguing, you overhear talk of a group of local Trolls who've been hassling the Orc group as of late\n Sensing an oppertunity to bargain for escape you raise your voice" << std::endl;
	std::cout << " You quickly strike a deal with the Orc leader,\n You help them work together to defeat the trolls when they return at sunrise,\n and you go free" << std::endl;
	std::cout << "[][][][][][][][][][][][][][][][][][][][][][][][]][][][][][][][][][][][][]][][][]" << std::endl;
}

void Game::combat()
{
	// loops through all the players Orcs
	for (int i = 0; i < 4; i++)
	{
		if (orcs[i]->getLife() == true)
		{
			int playerChoice = -1;
			while (playerChoice != 1 && playerChoice != 2 && playerChoice != 3)
			{
				std::cout << "What will Orc " << i + 1 << " do?\n" << " 1 = Attack(free, low damage)\n 2 = Defend(doubles defence until the turn ends)\n 3 = cast magic(costs MP, high damage) " << std::endl;
				std::cin >> playerChoice;
			}
			//----------------------------------------------Governs melee attacks---------------------------------------------\\ 
			if (playerChoice == 1)
			{
				std::cout << "[][][][][][][][][][][][][][][][][][][][][][][][][][][][][][][][][][][][][][][][]" << std::endl;
				int enemyChoice = -1;

				std::cout << "which troll will he attack?" << std::endl;
				std::cout << "[][][][][][][][][][][][][][][][][][][][][][][][][][][][][][][][][][][][][][][][]" << std::endl;

				std::cin >> enemyChoice;

				int damage = orcs[i]->attack();

				if (trolls[enemyChoice - 1]->getLife() == true)
				{
					trolls[enemyChoice - 1]->damaged(damage);
					std::cout << "Troll " << enemyChoice << " takes " << damage << " points of damage" << std::endl;
				}
				else
				{
					std::cout << "Target was already dead" << std::endl;
				}
				
				std::cout << "[][][][][][][][][][][][][][][][][][][][][][][][][][][][][][][][][][][][][][][][]" << std::endl;
			}
			//-----------------------------------------------Governs defending------------------------------------------------\\ 
			if (playerChoice == 2)
			{
				orcs[i]->defend();
				std::cout << "[][][][][][][][][][][][][][][][][][][][][][][][][][][][][][][][][][][][][][][][]" << std::endl;
				std::cout << "Orc " << i + 1 << "s defence is now doubled" << std::endl;
				std::cout << "[][][][][][][][][][][][][][][][][][][][][][][][][][][][][][][][][][][][][][][][]" << std::endl;
			}
			//-----------------------------------------------Governs casting spells-------------------------------------------\\ 
			if (playerChoice == 3)
			{
				std::cout << "[][][][][][][][][][][][][][][][][][][][][][][][][][][][][][][][][][][][][][][][]" << std::endl;
				int enemyChoice = -1;
				std::cout << "which troll will he attack?" << std::endl;
				std::cout << "[][][][][][][][][][][][][][][][][][][][][][][][][][][][][][][][][][][][][][][][]" << std::endl;
				std::cin >> enemyChoice;
				int damage = orcs[i]->spell();

				if (trolls[enemyChoice - 1]->getLife() == true)
				{
					trolls[enemyChoice - 1]->damaged(damage);
					std::cout << "Troll " << enemyChoice << " takes " << damage << " points of damage" << std::endl;
				}
				else
				{
					std::cout << "Target was already dead" << std::endl;
				}
				
				std::cout << "[][][][][][][][][][][[[][][][][][][][][][][][][][][][][][][][][][][][][][][][][]" << std::endl;
			}
		}
		
	}
}

void Game::enemyCombat()
{
	// loops through the trolls
	for (int i = 0; i < 4; i++)
	{
		//-----------------------------------------------Troll attacks-------------------------------------------\\ 
		if (trolls[i]->getLife() == true)
		{
			int target = rand() % 4 + 1;
			int damage = trolls[i]->attack();

			if (orcs[target - 1]->getLife() == true)
			{
				orcs[target - 1]->damaged(damage);

				std::cout << "[][][][][][][][][][][][][][][][][][][][][][][][][][][][][][][][][][][][][][][][]" << std::endl;
				std::cout << "Troll " << i + 1 << " Snarls and attacks Orc " << target << std::endl;
				std::cout << "[][][][][][][][][][][][][][][][][][][][][][][][][][][][][][][][][][][][][][][][]" << std::endl;
				std::cout << "Orc " << target << " takes " << damage << " points of damage" << std::endl;
			}
			else
			{
				std::cout << "The troll is distracted and does not take its turn" << std::endl;
			}
			
			std::cout << "[][][][][][][][][][][][][][][][][][][][][][][][][][][][][][][][][][][][][][][][]" << std::endl;
		}
		
	}
}
	

void Game::partyOrganization()
{
	// outputs the status of all orcs
	std::cout << "[][][][][][][][][][][][][][][][][][][][][][][][][][][][][][][][][][][][][][][][]" << std::endl;
	for (int i = 0; i < 4; i++)
	{
		std::cout << "Orc " << i +1 << " has " << orcs[i]->getHealth() << " HP remaining" << std::endl;
		std::cout << "Orc " << i +1 << " has " << orcs[i]->getMagic() << " MP remaining" << std::endl;
	}

	std::cout << "[][][][][][][][][][][][][][][][][][][][][][][][][][][][][][][][][][][][][][][][]" << std::endl;

	// outputs the status of all trolls
	for (int i = 0; i < 4; i++)
	{
		std::cout << "Troll " << i + 1 << " has " << trolls[i]->getHealth() << " HP remaining" << std::endl;
	}
	std::cout << "[][][][][][][][][][][][][][][][][][][][][][][][][][][][][][][][][][][][][][][][]" << std::endl;
}

void Game::endGame()
{
	//-----------------------------------------------------------------
	// if enemy or player runs out of units the game ends
	//-----------------------------------------------------------------
	if (orcs[0]->getHealth() <= 0 && orcs[1]->getHealth() <= 0 && orcs[2]->getHealth() <= 0 && orcs[3]->getHealth() <= 0)
	{
		std::cout << "[][][][][][][][][][][][][][][][][][][][][][][][][][][][][][][][][][][][][][][][]" << std::endl;
		std::cout << "everyone died, the end" << std::endl;
		std::cout << "[][][][][][][][][][][][][][][][][][][][][][][][][][][][][][][][][][][][][][][][]" << std::endl;
	}
	if (trolls[0]->getHealth() <= 0 && trolls[1]->getHealth() <= 0 && trolls[2]->getHealth() <= 0 && trolls[3]->getHealth() <= 0)
	{
		std::cout << "[][][][][][][][][][][][][][][][][][][][][][][][][][][][][][][][][][][][][][][][]" << std::endl;
		std::cout << " The battle is won,\n The Orcs still standing, thank you for your aid and allow you to return home." << std::endl;
		std::cout << "[][][][][][][][][][][][][][][][][][][][][][][][][][][][][][][][][][][][][][][][]" << std::endl;
	}
	
}


