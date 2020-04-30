#pragma once
#include "PCH.h"

class Player
{
private:

	Cells cell;
	std::string name;
	Field* field;
public:
	Player();
	bool MakeMove();
	std::string GetName();
	void InitPlayer(std::string name, Cells cell);
	void SetField(Field* field);
};

