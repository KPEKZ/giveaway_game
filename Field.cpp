#pragma once
#include "PCH.h"

Field::Field()
{
	this->iSizeField = 0;
	this->isAttackedWhite = false;
	this->isAttackedBlack = false;
	
}

void Field::CreateField()
{
	int iRowCount = 0;
	int iColCount = 0;

	

	cells.assign(this->iSizeField, std::vector<Cells>(this->iSizeField)); 

	for (it = cells.begin(); it != cells.end(); it++) {
		for (i = (*it).begin(); i != (*it).end(); i++) {
			 
			if (iColCount % 2 == 0) {
				
				if (iRowCount % 2 != 0 && iColCount < (this->iSizeField) - 5) {
										
					Cells c(Cells::State::BLACK);
					(*i) = c;
				}
				else if (iRowCount % 2 != 0 && iColCount > (this->iSizeField) - 4) {					
					Cells c(Cells::State::WHITE);
					(*i) = c;
				}
				else { 					
					Cells c(Cells::State::EMPTY);
					(*i) = c;}
			}
			else if (iColCount % 2 != 0) {
				if (iRowCount % 2 == 0 && iColCount < (this->iSizeField) - 5) {					
					Cells c(Cells::State::BLACK);
					(*i) = c;
				}
				else if (iRowCount % 2 == 0 && iColCount > (this->iSizeField) - 4) {					
					Cells c(Cells::State::WHITE);
					(*i) = c;
				}
				else {					
					Cells c(Cells::State::EMPTY);
					(*i) = c;
				}
			}
			
			iRowCount++;
			
		}
		iColCount++;
	}


}


void Field::SetSizeField(const int size)
{
	this->iSizeField = size;
}

void Field::DrawField()
{

	std::cout << std::endl;
	std::cout << std::endl;

	system("cls");
	std::cout << "    ";
	for (int key = 65,  j = 0; j < this->iSizeField ; j++, key++)
	{
		 std::cout << static_cast<char>(key) << " ";
		 
	}

	std::cout << std::endl;
	std::cout << std::endl;

	int keys = 1;
	
	

	for (it = cells.begin(); it != cells.end(); it++) {

		std::cout << " " << keys << "  ";
		for (i = (*it).begin(); i != (*it).end(); i++) {


			switch ((*i).GetState())
			{
			case Cells::State::EMPTY:
				std::cout << "_ ";
				break;
			case Cells::State::WHITE:
				std::cout << "O ";
				break;
			case Cells::State::BLACK:
				std::cout << "C "; //char(249)
				break;

			case Cells::State::QUEEN_W:
				std::cout << "W ";
				break;
			case Cells::State::QUEEN_B:
				std::cout << "B ";
				break;
			default:
				break;
			}

			if( i == (*it).end()-1)
				std::cout << " "<< keys;
			
		}
		std::cout << std::endl;
		keys++;
	}
	
	
	std::cout << std::endl;

	std::cout << "    ";
	for (int key = 65, j = 0; j < this->iSizeField; j++, key++)
	{
		std::cout << static_cast<char>(key) << " ";

	}

	std::cout << std::endl;
	std::cout << std::endl;

}

int Field::GetSizeField()
{
	return this->iSizeField;
}

void Field::DeleteCell(WORD xPos, WORD yPos)
{
	for (int j = 0; j < this->iSizeField; j++) {
		for (int i = 0; i < this->iSizeField; i++) {
			cells[yPos][xPos] = Cells::State::EMPTY;
		}
	}

	this->DrawField();

}

void Field::SetCell(WORD xPos, WORD yPos, Cells::State cell)
{
	for (int j = 0; j < this->iSizeField; j++) {
		for (int i = 0; i < this->iSizeField; i++) {
			cells[yPos][xPos] = cell;
		}
	}
	this->DrawField();
}

bool Field::ValidateChoose(Cells::position Pos, Cells cellPawn, Cells cellQueen)
{
	short int limit = 7;
	

	this->CheckSteps();
	if (this->isAttackedWhite || this->isAttackedBlack) {

		if (cellPawn.GetState() == Cells::State::WHITE && this->isAttackedWhite || 
			cellPawn.GetState() == Cells::State::BLACK && this->isAttackedBlack) {
			if (cells[Pos.second][Pos.first].GetCutt() == Cells::isCutting::YES) {
				if ((Pos.first >= 0 && Pos.first <= limit) && (Pos.second >= 0 && Pos.second <= limit)) { //сначала проверяем на принадлежность координат полю

					if (this->cells[Pos.second][Pos.first].GetState() != Cells::State::EMPTY && this->cells[Pos.second][Pos.first].GetState() == cellPawn.GetState()) { //проверка на соответствие типа шашки и не пустой клетки


						this->QueenMade();

						if (CheckCondition(cellPawn, Pos, limit)) return true;

					}
					else
						if (this->cells[Pos.second][Pos.first].GetState() != Cells::State::EMPTY && this->cells[Pos.second][Pos.first].GetState() == cellQueen.GetState()) {
							this->QueenMade();

							if (CheckCondition(cellQueen, Pos, limit)) return true;

						}

				}
			}
			
		}
		else {
			if (cells[Pos.second][Pos.first].GetCutt() == Cells::isCutting::NO)
				if ((Pos.first >= 0 && Pos.first <= limit) && (Pos.second >= 0 && Pos.second <= limit)) { //сначала проверяем на принадлежность координат полю

					if (this->cells[Pos.second][Pos.first].GetState() != Cells::State::EMPTY && this->cells[Pos.second][Pos.first].GetState() == cellPawn.GetState()) { //проверка на соответствие типа шашки и не пустой клетки


						this->QueenMade();

						if (CheckCondition(cellPawn, Pos, limit)) return true;

					}
					else
						if (this->cells[Pos.second][Pos.first].GetState() != Cells::State::EMPTY && this->cells[Pos.second][Pos.first].GetState() == cellQueen.GetState()) {
							this->QueenMade();

							if (CheckCondition(cellQueen, Pos, limit)) return true;

						}

				}
		}
		
	}
	else
	{
		if (cells[Pos.second][Pos.first].GetCutt() == Cells::isCutting::NO)
			if ((Pos.first >= 0 && Pos.first <= limit) && (Pos.second >= 0 && Pos.second <= limit)) { //сначала проверяем на принадлежность координат полю

				if (this->cells[Pos.second][Pos.first].GetState() != Cells::State::EMPTY && this->cells[Pos.second][Pos.first].GetState() == cellPawn.GetState()) { //проверка на соответствие типа шашки и не пустой клетки


					this->QueenMade();

					if (CheckCondition(cellPawn, Pos, limit)) return true;

				}
				else
					if (this->cells[Pos.second][Pos.first].GetState() != Cells::State::EMPTY && this->cells[Pos.second][Pos.first].GetState() == cellQueen.GetState()) {
						this->QueenMade();

						if (CheckCondition(cellQueen, Pos, limit)) return true;

					}

			}
	}

	return false;
		
}

bool Field::ValidateSell(Cells::position endPos, Cells cellPawn, Cells cellQueen, Field* field, Cells::position PrevPos)
{
	this->isEated = false;
	short int limit = 7;
	

	int dx = endPos.first - PrevPos.first; 
	int dy = endPos.second - PrevPos.second;


		if ((endPos.first >= 0 && endPos.first <= limit) && (endPos.second >= 0 && endPos.second <= limit)) { //сначала проверяем на принадлежность координат полю

			if (this->cells[endPos.second][endPos.first].GetState() == Cells::State::EMPTY) { //проверка на соответствие типа шашки и не пустой клетки

				if (this->cells[PrevPos.second][PrevPos.first].GetState() != Cells::State::QUEEN_W && this->cells[PrevPos.second][PrevPos.first].GetState() != Cells::State::QUEEN_B) {

					if (abs(dx) == 2 && abs(dy) == 2) { // если длина хода по х и у равны 2

						if (this->cells[PrevPos.second + (dy) / 2][PrevPos.first + (dx) / 2].GetState() != cellPawn.GetState() &&
							this->cells[PrevPos.second + (dy) / 2][PrevPos.first + (dx) / 2].GetState() != Cells::State::EMPTY) {

							field->DeleteCell(PrevPos.first, PrevPos.second);
							field->SetCell(endPos.first, endPos.second, cellPawn.GetState());
							field->DeleteCell(PrevPos.first + (dx) / 2, PrevPos.second + (dy) / 2);
							this->cells[PrevPos.second + (dy) / 2][PrevPos.first + (dx) / 2].SetCutt(Cells::isCutting::NO);
							for (int j{ 0 }; j < cells.size(); j++) {
								for (int i{ 0 }; i < cells.size(); i++) {
									if (cells[j][i].GetState() == cellPawn.GetState())
										cells[j][i].SetCutt(Cells::isCutting::NO);
								}
							}
							this->isEated = true;
							this->isAttackedBlack = false;
							this->isAttackedWhite = false;
							this->QueenMade();
							if (this->cells[PrevPos.second][PrevPos.first].GetState() == Cells::State::BLACK)
								this->countTryBlack++;
							else this->countTryWhite++;
							return true;

						}
					}
					else if (abs(dx) == 1 && abs(dy) == 1) { // если длина хода по х и у равны 1

						if (this->cells[PrevPos.second][PrevPos.first].GetState() == Cells::State::WHITE) { // проверка на ход назад (он не допустим)

							if (this->cells[PrevPos.second][PrevPos.first].GetCutt() == Cells::isCutting::NO)
							if ((endPos.second < PrevPos.second && endPos.first > PrevPos.first) ||
								(endPos.second < PrevPos.second && endPos.first < PrevPos.first)) {

								field->DeleteCell(PrevPos.first, PrevPos.second);
								field->SetCell(endPos.first, endPos.second, cellPawn.GetState());
								this->QueenMade();
								this->countTryWhite++;
								return true;
							}
						}
						else if (this->cells[PrevPos.second][PrevPos.first].GetState() == Cells::State::BLACK) { // проверка на ход назад (он не допустим)

							if (this->cells[PrevPos.second][PrevPos.first].GetCutt() == Cells::isCutting::NO)
							if ((endPos.second > PrevPos.second && endPos.first > PrevPos.first) ||
								(endPos.second > PrevPos.second && endPos.first < PrevPos.first)) {

								field->DeleteCell(PrevPos.first, PrevPos.second);
								field->SetCell(endPos.first, endPos.second, cellPawn.GetState());
								this->QueenMade();
								this->countTryBlack++;
								return true;
							}
						}


					}
					

				}
				else {

					if (this->cells[PrevPos.second][PrevPos.first].GetState() == Cells::State::QUEEN_W) {

						int dx = endPos.first - PrevPos.first;
						int dy = endPos.second - PrevPos.second;

						
						if (abs(dx) == abs(dy))
						if (PrevPos.second != endPos.second && PrevPos.first != endPos.first) {

							bool white{ false };
							int BlackX{ 0 };
							int BlackY{ 0 };
							int countBlack{ 0 };

							int j{ 0 }, i{ 0 };

							int counterY{ PrevPos.second };
							int counterX{ PrevPos.first };

							

							while (j <= abs(dx) && i <= abs(dy)) {


								if ((this->cells[counterY][counterX].GetState() == Cells::State::WHITE ||
									this->cells[counterY][counterX].GetState() == Cells::State::QUEEN_W) &&
									counterY != PrevPos.second) {
									white = true;
								}

								if ((this->cells[counterY][counterX].GetState() == Cells::State::BLACK ||
									this->cells[counterY][counterX].GetState() == Cells::State::QUEEN_B) &&
									counterY != PrevPos.second) {
									BlackY = counterY;
									BlackX = counterX;
									countBlack++;
								}

								if (endPos.second > PrevPos.second && endPos.first > PrevPos.first) {
									counterY++;
									counterX++;
								}
								else if (endPos.second < PrevPos.second && endPos.first < PrevPos.first) {
									counterY--;
									counterX--;
								}
								else if (endPos.second < PrevPos.second && endPos.first > PrevPos.first) {
									counterY--;
									counterX++;
								}
								else if (endPos.second > PrevPos.second && endPos.first < PrevPos.first) {
									counterY++;
									counterX--;
								}

								i++;
								j++;
							}
							
							

							if (!white) {

								if (cells[PrevPos.second][PrevPos.first].GetCutt() == Cells::isCutting::YES) {
									if (countBlack == 1) {
										field->DeleteCell(PrevPos.first, PrevPos.second);
										field->DeleteCell(BlackX, BlackY);
										field->SetCell(endPos.first, endPos.second, cellQueen.GetState());
										for (int j{ 0 }; j < cells.size(); j++) {
											for (int i{ 0 }; i < cells.size(); i++) {
												if (cells[j][i].GetState() == cellPawn.GetState())
													cells[j][i].SetCutt(Cells::isCutting::NO);
											}
										}
										this->isAttackedBlack = false;
										this->isAttackedWhite = false;
										this->countTryWhite++;
										this->isEated = true;
										return true;
									}
								}
								else {
									 if (countBlack == 0) {
										if (this->cells[PrevPos.second][PrevPos.first].GetCutt() == Cells::isCutting::NO) {
											field->DeleteCell(PrevPos.first, PrevPos.second);
											field->SetCell(endPos.first, endPos.second, cellQueen.GetState());
											this->countTryWhite++;
											return true;
										}
									 }
								}




							}

						}

						

					}

					if (this->cells[PrevPos.second][PrevPos.first].GetState() == Cells::State::QUEEN_B) {

						int dx = endPos.first - PrevPos.first;
						int dy = endPos.second - PrevPos.second;

						if (abs(dx) == abs(dy))
						if (PrevPos.second != endPos.second && PrevPos.first != endPos.first) {

							bool black{ false };
							int WhiteX{ 0 };
							int WhiteY{ 0 };
							int countWhite{ 0 };

							int j{ 0 }, i{ 0 };

							int counterY{ PrevPos.second };
							int counterX{ PrevPos.first };



							while (j <= abs(dx) && i <= abs(dy)) {


								if ((this->cells[counterY][counterX].GetState() == Cells::State::WHITE ||
									this->cells[counterY][counterX].GetState() == Cells::State::QUEEN_W) &&
									counterY != PrevPos.second) {
									WhiteY = counterY;
									WhiteX = counterX;
									countWhite++;
								}

								if ((this->cells[counterY][counterX].GetState() == Cells::State::BLACK ||
									this->cells[counterY][counterX].GetState() == Cells::State::QUEEN_B) &&
									counterY != PrevPos.second) {
									
									black = true;
								}

								if (endPos.second > PrevPos.second && endPos.first > PrevPos.first) {
									counterY++;
									counterX++;
								}
								else if (endPos.second < PrevPos.second && endPos.first < PrevPos.first) {
									counterY--;
									counterX--;
								}
								else if (endPos.second < PrevPos.second && endPos.first > PrevPos.first) {
									counterY--;
									counterX++;
								}
								else if (endPos.second > PrevPos.second && endPos.first < PrevPos.first) {
									counterY++;
									counterX--;
								}

								i++;
								j++;
							}



							if (!black) {

								if (cells[PrevPos.second][PrevPos.first].GetCutt() == Cells::isCutting::YES) {
									if (countWhite == 1) {
										field->DeleteCell(PrevPos.first, PrevPos.second);
										field->DeleteCell(WhiteX, WhiteY);
										field->SetCell(endPos.first, endPos.second, cellQueen.GetState());
										for (int j{ 0 }; j < cells.size(); j++) {
											for (int i{ 0 }; i < cells.size(); i++) {
												if (cells[j][i].GetState() == cellPawn.GetState())
													cells[j][i].SetCutt(Cells::isCutting::NO);
											}
										}
										this->isAttackedBlack = false;
										this->isAttackedWhite = false;
										this->countTryBlack++;
										this->isEated = true;
										return true;
									}
								}
								else{ 
									if (countWhite == 0) {
										field->DeleteCell(PrevPos.first, PrevPos.second);
										field->SetCell(endPos.first, endPos.second, cellQueen.GetState());
										this->countTryBlack++;
										return true;
									}
								}




							}

						}


					}

				}

				
				

			}

			
		}

	

	return false;
}

Cells::position Field::CoordPerform(std::string s)
{
	char cfirst_letter = toupper(s[0]);
	const char* cSecond_letter = &s[1];
	int iFirst_letter = static_cast<int>(cfirst_letter) - 65;
	int iSecond_letter = (atoi(cSecond_letter))-1;

	Cells::position pos = Cells::position(iFirst_letter, iSecond_letter);
	return pos;

}

bool Field::CheckCondition(Cells cell, Cells::position Pos, short int limit)
{
	bool a{ false }, b{ false };


		if (cell.GetState() == Cells::State::WHITE)
			a = this->CheckWhite(cell, Pos, limit);
		else if (cell.GetState() == Cells::State::QUEEN_W)
			a = this->CheckWhiteQueen(cell, Pos, limit);
		

		if (cell.GetState() == Cells::State::BLACK)
			b = this->CheckBlack(cell, Pos, limit);
		else if (cell.GetState() == Cells::State::QUEEN_B)
			b = this->CheckBlackQueen(cell, Pos, limit);
		

	if (a || b) return true;

	return false;

}

bool Field::CheckWhite(Cells cell, Cells::position Pos, short int limit)
{


	bool rightTop = false;
	bool rightBottom = false;
	bool leftTop = false;
	bool leftBottom = false;
	bool isMet = false; // встреча на пути вражеской фигуры

	int counter = 1; // длина пути



	// проверка верхней диагонали справа от шашки
	while ((Pos.second - counter >= 0) && (Pos.first + counter <= limit)) {

		

		if (cells[Pos.second - counter][Pos.first + counter].GetState() == Cells::State::EMPTY && counter == 1) {
			rightTop = true;
		}

		if ((cells[Pos.second - counter][Pos.first + counter].GetState() == Cells::State::BLACK || 
			cells[Pos.second - counter][Pos.first + counter].GetState() == Cells::State::QUEEN_B
			) && counter == 1) {
			isMet = true;

		}

		if ((cells[Pos.second - counter][Pos.first + counter].GetState() == Cells::State::EMPTY && counter == 2) && isMet == true) {

			//this->isAttacked = true;
			rightTop = true;
			isMet = false;
		}

		counter++;
	}



	// проверка верхней диагонали слева от шашки

	counter = 1;

	while ((Pos.first - counter >= 0) && (Pos.second - counter >= 0)) {

		

		if (cells[Pos.second - counter][Pos.first - counter].GetState() == Cells::State::EMPTY && counter == 1) {
			leftTop = true;
		}

		if ((cells[Pos.second - counter][Pos.first - counter].GetState() == Cells::State::BLACK ||
			cells[Pos.second - counter][Pos.first - counter].GetState() == Cells::State::QUEEN_B) && counter == 1) {
			isMet = true;

		}

		if ((cells[Pos.second - counter][Pos.first - counter].GetState() == Cells::State::EMPTY && counter == 2) && isMet == true) {

			//this->isAttacked = true;
			leftTop = true;
			isMet = false;
		}

		counter++;
	}

	counter = 1;



	// проверка нижней диагонали справа от шашки
	while ((Pos.second + counter <= limit) && (Pos.first + counter <= limit)) {
		
		if ((cells[Pos.second + counter][Pos.first + counter].GetState() == Cells::State::BLACK || 
			cells[Pos.second + counter][Pos.first + counter].GetState() == Cells::State::QUEEN_B) && counter == 1) {
			isMet = true;

		}

		if ((cells[Pos.second + counter][Pos.first + counter].GetState() == Cells::State::EMPTY && counter == 2) && isMet == true) {

			//this->isAttacked = true;
			rightBottom = true;
			isMet = false;
		}

		counter++;
	}



	// проверка нижней диагонали слева от шашки

	counter = 1;

	while ((Pos.first - counter >= 0) && (Pos.second + counter <= limit)) {

		

		if ((cells[Pos.second + counter][Pos.first - counter].GetState() == Cells::State::BLACK||
			cells[Pos.second + counter][Pos.first - counter].GetState() == Cells::State::QUEEN_B) && counter == 1) {
			isMet = true;

		}

		if ((cells[Pos.second + counter][Pos.first - counter].GetState() == Cells::State::EMPTY && counter == 2) && isMet == true) {

			//this->isAttacked = true;
			leftBottom = true;
			isMet = false;
		}

		counter++;
	}






	if ((leftTop || rightTop || leftBottom || rightBottom))
		return true;

	return false;
}

bool Field::CheckWhiteQueen(Cells cell, Cells::position Pos, short int limit)
{

	bool rightTop = true;
	bool rightBottom = true;
	bool leftTop = true;
	bool leftBottom = true;
	bool isMet = false; // встреча на пути вражеской фигуры

	int counter = 1; // длина пути



	// проверка верхней диагонали справа от шашки
	while ((Pos.second - counter >= 0) && (Pos.first + counter <= limit)) {



		if (cells[Pos.second - counter][Pos.first + counter].GetState() != Cells::State::EMPTY && counter == 1) {
			isMet = true;
		}

		if ((cells[Pos.second - counter][Pos.first + counter].GetState() != Cells::State::EMPTY && counter == 2) && isMet == true) {

			rightTop = false;
			isMet = false;
		}

		counter++;
	}



	// проверка верхней диагонали слева от шашки

	counter = 1;

	while ((Pos.first - counter >= 0) && (Pos.second - counter >= 0)) {



		if (cells[Pos.second - counter][Pos.first - counter].GetState() != Cells::State::EMPTY && counter == 1) {
			isMet = true;
		}

		if ((cells[Pos.second - counter][Pos.first - counter].GetState() != Cells::State::EMPTY && counter == 2) && isMet == true) {

			leftTop = false;
			isMet = false;
		}

		counter++;
	}

	counter = 1;



	// проверка нижней диагонали справа от шашки
	while ((Pos.second + counter <= limit) && (Pos.first + counter <= limit)) {

		if (cells[Pos.second + counter][Pos.first + counter].GetState() != Cells::State::EMPTY && counter == 1) {
			isMet = true;

		}

		if ((cells[Pos.second + counter][Pos.first + counter].GetState() != Cells::State::EMPTY && counter == 2) && isMet == true) {

			
			rightBottom = false;
			isMet = false;
		}

		counter++;
	}



	// проверка нижней диагонали слева от шашки

	counter = 1;

	while ((Pos.first - counter >= 0) && (Pos.second + counter <= limit)) {



		if (cells[Pos.second + counter][Pos.first - counter].GetState() != Cells::State::EMPTY && counter == 1) {
			isMet = true;

		}

		if ((cells[Pos.second + counter][Pos.first - counter].GetState() != Cells::State::EMPTY && counter == 2) && isMet == true) {

			leftBottom = false;
			isMet = false;
		}

		counter++;
	}






	if ((leftTop || rightTop || leftBottom || rightBottom))
		return true;


	return false;
}


bool Field::CheckBlack(Cells cell, Cells::position Pos, short int limit)
{

	bool rightTop = false;
	bool rightBottom = false;
	bool leftTop = false;
	bool leftBottom = false;
	int counter = 1; // длина пути
	bool isMet = false; // встреча на пути вражеской фигуры

	// проверка верхней диагонали справа от шашки
	while ((Pos.second - counter >= 0) && (Pos.first + counter <= limit)) {

		


		if ((cells[Pos.second - counter][Pos.first + counter].GetState() == Cells::State::WHITE ||
			cells[Pos.second - counter][Pos.first + counter].GetState() == Cells::State::QUEEN_W) && counter == 1) {
			isMet = true;

		}

		if ((cells[Pos.second - counter][Pos.first + counter].GetState() == Cells::State::EMPTY && counter == 2) && isMet == true) {

			//this->isAttacked = true;
			rightTop = true;
			isMet = false;
		}

		counter++;
	}



	// проверка верхней диагонали слева от шашки

	counter = 1;

	while ((Pos.first - counter >= 0) && (Pos.second - counter >= 0)) {

		
		if ((cells[Pos.second - counter][Pos.first - counter].GetState() == Cells::State::WHITE ||
			cells[Pos.second - counter][Pos.first - counter].GetState() == Cells::State::QUEEN_W) && counter == 1) {
			isMet = true;

		}

		if ((cells[Pos.second - counter][Pos.first - counter].GetState() == Cells::State::EMPTY && counter == 2) && isMet == true) {

			//this->isAttacked = true;
			leftTop = true;
			isMet = false;
		}

		counter++;
	}

	counter = 1;

	// проверка нижней диагонали справа от шашки
	while ((Pos.second + counter <= limit) && (Pos.first + counter <= limit)) {
		
		if (cells[Pos.second + counter][Pos.first + counter].GetState() == Cells::State::EMPTY && counter == 1) {
			rightBottom = true;
		}

		if ((cells[Pos.second + counter][Pos.first + counter].GetState() == Cells::State::WHITE ||
			cells[Pos.second + counter][Pos.first + counter].GetState() == Cells::State::QUEEN_W) && counter == 1) {
			isMet = true;

		}

		if ((cells[Pos.second + counter][Pos.first + counter].GetState() == Cells::State::EMPTY && counter == 2) && isMet == true) {

			//this->isAttacked = true;
			rightBottom = true;
			isMet = false;
		}

		counter++;
	}



	// проверка нижней диагонали слева от шашки

	counter = 1;

	while ((Pos.first - counter >= 0) && (Pos.second + counter <= limit)) {

		

		if (cells[Pos.second + counter][Pos.first - counter].GetState() == Cells::State::EMPTY && counter == 1) {
			leftBottom = true;
		}

		if ((cells[Pos.second + counter][Pos.first - counter].GetState() == Cells::State::WHITE||
			cells[Pos.second + counter][Pos.first - counter].GetState() == Cells::State::QUEEN_W) && counter == 1) {
			isMet = true;

		}

		if ((cells[Pos.second + counter][Pos.first - counter].GetState() == Cells::State::EMPTY && counter == 2) && isMet == true) {

			//this->isAttacked = true;
			leftBottom = true;
			isMet = false;
		}

		counter++;
	}

	if ((leftTop || rightTop || leftBottom || rightBottom))
		return true;


	return false;
}

bool Field::CheckBlackQueen(Cells cell, Cells::position Pos, short int limit)
{

	bool rightTop = true;
	bool rightBottom = true;
	bool leftTop = true;
	bool leftBottom = true;
	bool isMet = false; // встреча на пути вражеской фигуры

	int counter = 1; // длина пути



	// проверка верхней диагонали справа от шашки
	while ((Pos.second - counter >= 0) && (Pos.first + counter <= limit)) {



		if (cells[Pos.second - counter][Pos.first + counter].GetState() != Cells::State::EMPTY && counter == 1) {
			isMet = true;
		}

		if ((cells[Pos.second - counter][Pos.first + counter].GetState() != Cells::State::EMPTY && counter == 2) && isMet == true) {

			rightTop = false;
			isMet = false;
		}

		counter++;
	}



	// проверка верхней диагонали слева от шашки

	counter = 1;

	while ((Pos.first - counter >= 0) && (Pos.second - counter >= 0)) {



		if (cells[Pos.second - counter][Pos.first - counter].GetState() != Cells::State::EMPTY && counter == 1) {
			isMet = true;
		}

		if ((cells[Pos.second - counter][Pos.first - counter].GetState() != Cells::State::EMPTY && counter == 2) && isMet == true) {

			leftTop = false;
			isMet = false;
		}

		counter++;
	}

	counter = 1;



	// проверка нижней диагонали справа от шашки
	while ((Pos.second + counter <= limit) && (Pos.first + counter <= limit)) {

		if (cells[Pos.second + counter][Pos.first + counter].GetState() != Cells::State::EMPTY && counter == 1) {
			isMet = true;

		}

		if ((cells[Pos.second + counter][Pos.first + counter].GetState() != Cells::State::EMPTY && counter == 2) && isMet == true) {


			rightBottom = false;
			isMet = false;
		}

		counter++;
	}



	// проверка нижней диагонали слева от шашки

	counter = 1;

	while ((Pos.first - counter >= 0) && (Pos.second + counter <= limit)) {



		if (cells[Pos.second + counter][Pos.first - counter].GetState() != Cells::State::EMPTY && counter == 1) {
			isMet = true;

		}

		if ((cells[Pos.second + counter][Pos.first - counter].GetState() != Cells::State::EMPTY && counter == 2) && isMet == true) {

			leftBottom = false;
			isMet = false;
		}

		counter++;
	}



	if ((leftTop || rightTop || leftBottom || rightBottom))
		return true;



	return false;
}

void Field::CheckSteps()
{
	int limit = 7;

	for (int j = 0; j < this->iSizeField; j++) {
		for (int i = 0; i < this->iSizeField; i++) {
			if (cells[j][i].GetState() == Cells::State::WHITE ||
				cells[j][i].GetState() == Cells::State::QUEEN_W
				) {

				int counter{ 1 };
				int yPos = j;
				int xPos = i;

				

				bool rightTopFirst{ false };
				bool rightTopFirstEmpty{ false };
				bool leftTopFirst{ false };
				bool leftTopFirstEmpty{ false };
				bool rightBottomFirst{ false };
				bool rightBottomFirstEmpty{ false };
				bool leftBottomFirst{ false };
				bool leftBottomFirstEmpty{ false };

				bool rightTopSecond{ false };
				bool rightTopSecondEmpty{ false };
				bool leftTopSecond{ false };
				bool leftTopSecondEmpty{ false };
				bool rightBottomSecond{ false };
				bool rightBottomSecondEmpty{ false };
				bool leftBottomSecond{ false };
				bool leftBottomSecondEmpty{ false };


				// проверка верхней диагонали слева от шашки

				
				while ((yPos - counter >= 0) && (xPos - counter >= 0)) {



					if ((cells[yPos - counter][xPos - counter].GetState() == Cells::State::BLACK || cells[yPos - counter][xPos - counter].GetState() == Cells::State::QUEEN_B) && counter == 1) {

						leftTopFirst = true;

					}
					else if (cells[yPos - counter][xPos - counter].GetState() == Cells::State::EMPTY && counter == 1) {
						leftTopFirstEmpty = true;
					}

					if ((cells[yPos - counter][xPos - counter].GetState() == Cells::State::EMPTY && counter == 2) == true) {

						leftTopSecondEmpty = true;
					}


					counter++;
				}

				

				// проверка нижней диагонали слева от шашки

				counter = 1;

				while ((xPos - counter >= 0) && (yPos + counter <= limit)) {



					if ((cells[yPos + counter][xPos - counter].GetState() == Cells::State::BLACK || cells[yPos + counter][xPos - counter].GetState() == Cells::State::QUEEN_B) && counter == 1) {
						leftBottomFirst = true;

					}
					else if (cells[yPos + counter][xPos - counter].GetState() == Cells::State::EMPTY && counter == 1)
						leftBottomFirstEmpty = true;

					if ((cells[yPos + counter][xPos - counter].GetState() == Cells::State::EMPTY && counter == 2)) {

						leftBottomSecondEmpty = true;
					}

					counter++;
				}

				counter = 1;
			
				// проверка нижней диагонали справа от шашки
				while ((yPos - counter >= 0) && (xPos + counter <= limit)) {


					if ((cells[yPos - counter][xPos + counter].GetState() == Cells::State::BLACK || cells[yPos - counter][xPos + counter].GetState() == Cells::State::QUEEN_B) && counter == 1) {
						
						rightTopFirst = true;
					}
					else if (cells[yPos - counter][xPos + counter].GetState() == Cells::State::EMPTY && counter == 1) {
						rightTopFirstEmpty = true;
					}

					if ((cells[yPos - counter][xPos + counter].GetState() == Cells::State::EMPTY && counter == 2)) {
						rightTopSecondEmpty = true;
					}

					counter++;
				}



				counter = 1;

				// проверка нижней диагонали справа от шашки
				while ((yPos + counter <= limit) && (xPos + counter <= limit)) {

					if ((cells[yPos + counter][xPos + counter].GetState() == Cells::State::BLACK || cells[yPos + counter][xPos + counter].GetState() == Cells::State::QUEEN_B) && counter == 1) {
						rightBottomFirst = true;

					} 
					else if (cells[yPos + counter][xPos + counter].GetState() == Cells::State::EMPTY && counter == 1) {
						rightBottomFirstEmpty = 0;
					}

					if ((cells[yPos + counter][xPos + counter].GetState() == Cells::State::EMPTY && counter == 2)) {

						rightBottomSecondEmpty = true;
					}

					counter++;
				}


				
				
				// проверка ссверху
				if ((rightTopFirst && rightTopSecondEmpty && !leftBottomFirstEmpty) || (leftTopFirst && leftTopSecondEmpty && !rightBottomFirstEmpty)) {
					this->isAttackedWhite = true;
					cells[j][i].SetCutt(Cells::isCutting::YES);
				}
					

				if ((rightTopFirst && rightTopSecondEmpty && leftBottomFirstEmpty) || (leftTopFirst && leftTopSecondEmpty && rightBottomFirstEmpty)) {
					this->isAttackedWhite = true;
					cells[j][i].SetCutt(Cells::isCutting::YES);
				}
					
				// проверка снизу
				if ((rightBottomFirst && rightBottomSecondEmpty && !leftTopFirstEmpty) || (leftBottomFirst && leftBottomSecondEmpty && !rightTopFirstEmpty)) {
					this->isAttackedWhite = true;
					cells[j][i].SetCutt(Cells::isCutting::YES);
				}


				if ((rightBottomFirst && rightBottomSecondEmpty && leftTopFirstEmpty) || (leftBottomFirst && leftBottomSecondEmpty && rightTopFirstEmpty)) {
					this->isAttackedWhite = true;
					cells[j][i].SetCutt(Cells::isCutting::YES);
				}

			}


			if (cells[j][i].GetState() == Cells::State::BLACK ||
				cells[j][i].GetState() == Cells::State::QUEEN_B)
			{

				int counter{ 1 };
				int yPos = j;
				int xPos = i;



				bool rightTopFirst{ false };
				bool rightTopFirstEmpty{ false };
				bool leftTopFirst{ false };
				bool leftTopFirstEmpty{ false };
				bool rightBottomFirst{ false };
				bool rightBottomFirstEmpty{ false };
				bool leftBottomFirst{ false };
				bool leftBottomFirstEmpty{ false };

				bool rightTopSecond{ false };
				bool rightTopSecondEmpty{ false };
				bool leftTopSecond{ false };
				bool leftTopSecondEmpty{ false };
				bool rightBottomSecond{ false };
				bool rightBottomSecondEmpty{ false };
				bool leftBottomSecond{ false };
				bool leftBottomSecondEmpty{ false };


				// проверка верхней диагонали слева от шашки


				while ((yPos - counter >= 0) && (xPos - counter >= 0)) {



					if ((cells[yPos - counter][xPos - counter].GetState() == Cells::State::WHITE || cells[yPos - counter][xPos - counter].GetState() == Cells::State::QUEEN_W) && counter == 1) {

						leftTopFirst = true;

					}
					else if (cells[yPos - counter][xPos - counter].GetState() == Cells::State::EMPTY && counter == 1) {
						leftTopFirstEmpty = true;
					}

					if ((cells[yPos - counter][xPos - counter].GetState() == Cells::State::EMPTY && counter == 2) == true) {

						leftTopSecondEmpty = true;
					}


					counter++;
				}

				counter = 1;

				// проверка нижней диагонали слева от шашки

				

				while ((xPos - counter >= 0) && (yPos + counter <= limit)) {



					if ((cells[yPos + counter][xPos - counter].GetState() == Cells::State::WHITE || cells[yPos + counter][xPos - counter].GetState() == Cells::State::QUEEN_W) && counter == 1) {
						leftBottomFirst = true;

					}
					else if (cells[yPos + counter][xPos - counter].GetState() == Cells::State::EMPTY && counter == 1)
						leftBottomFirstEmpty = true;

					if ((cells[yPos + counter][xPos - counter].GetState() == Cells::State::EMPTY && counter == 2)) {

						leftBottomSecondEmpty = true;
					}

					counter++;
				}

				counter = 1;

				// проверка нижней диагонали справа от шашки
				while ((yPos - counter >= 0) && (xPos + counter <= limit)) {


					if ((cells[yPos - counter][xPos + counter].GetState() == Cells::State::WHITE || cells[yPos - counter][xPos + counter].GetState() == Cells::State::QUEEN_W) && counter == 1) {

						rightTopFirst = true;
					}
					else if (cells[yPos - counter][xPos + counter].GetState() == Cells::State::EMPTY && counter == 1) {
						rightTopFirstEmpty = true;
					}

					if ((cells[yPos - counter][xPos + counter].GetState() == Cells::State::EMPTY && counter == 2)) {
						rightTopSecondEmpty = true;
					}

					counter++;
				}


				counter = 1;


				// проверка нижней диагонали справа от шашки
				while ((yPos + counter <= limit) && (xPos + counter <= limit)) {

					if ((cells[yPos + counter][xPos + counter].GetState() == Cells::State::WHITE || cells[yPos + counter][xPos + counter].GetState() == Cells::State::QUEEN_W) && counter == 1) {
						rightBottomFirst = true;

					}
					else if (cells[yPos + counter][xPos + counter].GetState() == Cells::State::EMPTY && counter == 1) {
						rightBottomFirstEmpty = 0;
					}

					if ((cells[yPos + counter][xPos + counter].GetState() == Cells::State::EMPTY && counter == 2)) {

						rightBottomSecondEmpty = true;
					}

					counter++;
				}




				// проверка ссверху
				if ((rightTopFirst && rightTopSecondEmpty && !leftBottomFirstEmpty) || (leftTopFirst && leftTopSecondEmpty && !rightBottomFirstEmpty)) {
					this->isAttackedBlack = true;
					cells[j][i].SetCutt(Cells::isCutting::YES);
				}


				if ((rightTopFirst && rightTopSecondEmpty && leftBottomFirstEmpty) || (leftTopFirst && leftTopSecondEmpty && rightBottomFirstEmpty)) {
					this->isAttackedBlack = true;
					cells[j][i].SetCutt(Cells::isCutting::YES);
				}


				// проверка снизу
				if ((rightBottomFirst && rightBottomSecondEmpty && !leftTopFirstEmpty) || (leftBottomFirst && leftBottomSecondEmpty && !rightTopFirstEmpty)) {
					this->isAttackedBlack = true;
					cells[j][i].SetCutt(Cells::isCutting::YES);
				}


				if ((rightBottomFirst && rightBottomSecondEmpty && leftTopFirstEmpty) || (leftBottomFirst && leftBottomSecondEmpty && rightTopFirstEmpty)) {					
					this->isAttackedBlack = true;
					cells[j][i].SetCutt(Cells::isCutting::YES);
				}


			}
			

		}
	}


}

void Field::QueenMade()
{
	for (int j = 0; j < this->iSizeField; j++) {
		for (int i = 0; i < this->iSizeField; i++) {

			if (cells[j][i].GetState() == Cells::State::WHITE) {
				if (j == 0) {
					cells[j][i].SetState(Cells::State::QUEEN_W);
				}
			}

			if (cells[j][i].GetState() == Cells::State::BLACK) {
				if (j == this->iSizeField-1) {
					cells[j][i].SetState(Cells::State::QUEEN_B);
				}
			}
		}
	}
}

bool Field::Victory()
{
	int countWhite{ 0 };
	int countBlack{ 0 };
	for (int j{ 0 }; j < this->iSizeField; j++) {
		for (int i{ 0 }; i < this->iSizeField; i++) {
			if (this->cells[j][i].GetState() == Cells::State::WHITE ||
				this->cells[j][i].GetState() == Cells::State::QUEEN_W)
				countWhite++;
			if (this->cells[j][i].GetState() == Cells::State::BLACK ||
				this->cells[j][i].GetState() == Cells::State::QUEEN_B)
				countBlack++;
				
		}
	}

	if (countBlack == 0 && countWhite > 0) { 
		this->blackWin = true;
		return true; }
	else if (countWhite == 0 && countBlack > 0) { 
		this->whiteWin = true;
		return true; }
	else
		return false;
}
