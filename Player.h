#pragma once
#include "PCH.h"

class Player
{
private:

	Cells cellPawn;
	Cells cellQueen;
	std::string name;
	Field* field;
public:
	Player();
	bool MakeMove();
	std::string GetName();
	void InitPlayer(std::string name, Cells cellPawn, Cells cellQueen);
	void SetField(Field* field);
};

