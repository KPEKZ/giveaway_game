#pragma once
#include "PCH.h"

Player::Player()
{
	
	this->name = "";
	this->field = nullptr;
	
}

bool Player::MakeMove()
{
	std::cout << "Player " << this->name << ", you turn..." << "Choose the figure : ";
	std::string s; // координаты игрока 
	std::cin >> s;

	Cells::position pos;

	if (!s.empty() && s.length() != 1) {


		pos = this->field->CoordPerform(s);

		if (this->field->ValidateChoose(pos, this->cell)) {


			pos = this->field->CoordPerform(s);

			std::cout << "your choice:  " << pos.first << " " << pos.second << std::endl;

			//this->field->ChooseCell(s, this->cell, this->field);
			std::cout << "enter you coords: ";
			std::cin >> s;

			if (!s.empty() && s.length() != 1) {

				Cells::position endPos;
				endPos = this->field->CoordPerform(s);

				if (this->field->ValidateSell(endPos, this->cell, this->field, pos))
				{

					return true;
				}
			}

		}
	}
	
	return false;
}

std::string Player::GetName()
{
	return this->name;
}

void Player::InitPlayer(std::string name, Cells cell)
{
	this->name = name;
	this->cell = cell;
}

void Player::SetField(Field* field)
{
	this->field = field;
}
