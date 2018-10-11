#pragma once
#include <iostream>
#include "Orc.h"
#include "Troll.h"


class Game
{
public:
	Game();
	void run();
	void introduction();
	void combat();
	void enemyCombat();
	void partyOrganization();
	void endGame();

private:
	bool m_gameOver = false;
	
	Character * orcs[4];

	Character * trolls[4];

	int noOfLivingTrolls;

};