#pragma once
#include <iostream>
#include "Orc.h"
#include "Troll.h"


class Game
{
public:
	Game();
	void run(); // controls the game loop
	void introduction(); // outputs the opnening plot dump
	void combat();// takes the users turn
	void enemyCombat();// takes the enemies turn
	void partyOrganization();// outputs the current status of the enemies and allies
	void endGame();// outputs a ending message based on if you won or lost

private:
	bool m_gameOver = false;// controls the main game loop
	
	Character * orcs[4];// the characters controlled by the player, pointers

	Character * trolls[4];// the characters conotrolled by AI, pointers

};