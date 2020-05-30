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

		if (this->field->ValidateChoose(pos, this->cellPawn, this->cellQueen)) {


			pos = this->field->CoordPerform(s);

			std::cout << "your choice:  " << pos.first << " " << pos.second << std::endl;

			
			std::cout << "enter you coords: ";
			std::cin >> s;

			if (!s.empty() && s.length() != 1) {

				Cells::position endPos;
				endPos = this->field->CoordPerform(s);

				if (this->field->ValidateSell(endPos, this->cellPawn, this->cellQueen, this->field, pos)) {

					if (this->field->isEated)
						this->field->CheckSteps();
					if (!this->field->isAttackedWhite || !this->field->isAttackedBlack) {
						return true;
					}

					this->field->isAttackedBlack = false;
					this->field->isAttackedWhite = false;
					this->field->isEated = false;
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

void Player::InitPlayer(std::string name, Cells cellPawn, Cells cellQueen)
{
	this->name = name;
	this->cellPawn = cellPawn;
	this->cellQueen = cellQueen;
}

void Player::SetField(Field* field)
{
	this->field = field;
}
