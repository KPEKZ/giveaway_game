#pragma once
#include "PCH.h"
class Manager
{

private:
	Player* player1;
	Player* player2;
	Player* currentPlayer;
	Field *field;
	
public:
	bool gGameFinished{ false };
	Manager();
	bool Init();
	void MakeMove();
	virtual ~Manager();
};

