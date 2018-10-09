#include <iostream>

using namespace std;

class Character {
public:
	void flip() { cout << "I know how to flip and I will flipping do it" << endl; }
	virtual void walk() { cout << "just in case they are too young to walk yet" << endl; }
	virtual void fly() = 0; //pure virtual function

private:
	int healthPoints = 0;
	int magicPoints = 0;
	int strength = 0;
	int agility = 0;
	int intelligence = 0;
};

class Orc : public Character {
public:
	void barrelRoll() { cout << "rooooooolllllllllllinggggggg" << endl; }
	void walk() { cout << "Doopers have a really cool walk!" << endl; }
	void fly() { cout << "Dooper is flapping and flying" << endl; }

};

class Troll : public Character {
public:
	void fly() { cout << "Average Dooper is flapping and flying" << endl; }
};

void introduction()
{
	std::cout << "P L O T" << std::endl;
}

void partyOrganisation()
{
	std::cout << "P A R T Y" << std::endl;
};

void turnChange()
{
	std::cout << "T U R N  C H A N G E" << std::endl;
}

void combat()
{
	turnChange();
}

int main(void)
{
	
	bool gameOver = false;

	enum OrcTurns {
		Reggie, 
	    Snaggle,
		Squee,
		RogRog
	};

	enum trollTurns {
		blarg,
		blorg,
		glarg,
		Harold
	};

	

	introduction();

	while (gameOver == false)
	{
		
		partyOrganisation();
		combat();

	}
	
	std::system("pause");
	return 0;
}

