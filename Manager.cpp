#pragma once
#include "PCH.h"

Manager::Manager()
{
	player1 = player2 = nullptr;
	currentPlayer = nullptr;
	field = nullptr;
}

bool Manager::Init()
{
	this->field = new Field();
	this->field->SetSizeField(8);
	this->field->CreateField();
	this->field->DrawField();
	this->player1 = new Player();
	this->player2 = new Player();
	std::cout << std::endl;
	std::string name;
	std::cout << "enter the name player of WHITE: ";
	std::cin >> name;
	player1->InitPlayer(name, Cells::State::WHITE, Cells::State::QUEEN_W);
	player1->SetField(this->field);
	std::cout << std::endl;
	std::cout << "enter the name player of BLACK: ";
	std::cin >> name;
	player2->InitPlayer(name, Cells::State::BLACK, Cells::State::QUEEN_B);
	player2->SetField(this->field);
	std::cout << std::endl;
	currentPlayer = player1;
	return true;
}

void Manager::MakeMove()
{
	while (!currentPlayer->MakeMove()) {
		std::cout << std::endl;
		std::cout << " impossible turn, try again!" << std::endl;
	}

	currentPlayer = (currentPlayer == player1) ? player2 : player1;
}

Manager::~Manager()
{
	delete this->field;
	delete this->player1;
	delete this->player2;
}
