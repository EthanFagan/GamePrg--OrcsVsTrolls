#include "Game.h"
#include <iostream>

void Game::run()
{
	while (gameOver == false)
	{

		partyOrganization();
		combat();

	}
}

void Game::introduction()
{
	std::cout << "P L O T" << std::endl;
}

void Game::combat()
{
	turnChange();
}

void Game::turnChange()
{
	std::cout << "T U R N  C H A N G E" << std::endl;
}

void Game::partyOrganization()
{
	std::cout << "P A R T Y" << std::endl;
}
