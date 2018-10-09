#pragma once
#include <iostream>
#include "Character.h"


class Game
{
public:
	void run();
	void introduction();
	void combat();
	void turnChange();
	void partyOrganization();
	

private:
	bool gameOver = false;
	//-------------------------
	Orc reggie;
	Orc snaggle;
	Orc squee;
	Orc rogrog;
	//-------------------------
	Troll blarg;
	Troll blorg;
	Troll glarg;
	Troll harold;
	//--------------------------

	enum OrcTurns {
		ReggieTurn,
		SnaggleTurn,
		SqueeTurn,
		RogRogTurn
	};

	enum trollTurns {
		blargTurn,
		blorgTurn,
		glargTurn,
		HaroldTurn
	};
};