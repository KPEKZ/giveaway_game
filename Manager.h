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
	Manager();
	bool Init();
	void MakeMove();
	virtual ~Manager();
};

