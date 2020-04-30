#pragma once
#include "PCH.h"

Field::Field()
{
	this->iSizeField = 0;
	
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
					
					Cells::position pos = Cells::position(iRowCount,iColCount);
					Cells c(Cells::State::BLACK);
					(*i) = c;
				}
				else if (iRowCount % 2 != 0 && iColCount > (this->iSizeField) - 4) {
					Cells::position pos = Cells::position(iRowCount, iColCount);
					Cells c(Cells::State::WHITE);
					(*i) = c;
				}
				else { 
					Cells::position pos = Cells::position(iRowCount, iColCount);
					Cells c(Cells::State::EMPTY);
					(*i) = c;}
			}
			else if (iColCount % 2 != 0) {
				if (iRowCount % 2 == 0 && iColCount < (this->iSizeField) - 5) {
					Cells::position pos = Cells::position(iRowCount, iColCount);
					Cells c(Cells::State::BLACK);
					(*i) = c;
				}
				else if (iRowCount % 2 == 0 && iColCount > (this->iSizeField) - 4) {
					Cells::position pos = Cells::position(iRowCount, iColCount);
					Cells c(Cells::State::WHITE);
					(*i) = c;
				}
				else {
					Cells::position pos = Cells::position(iRowCount, iColCount);
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
	system("cls");
	std::cout << "  ";
	for (int key = 65,  j = 0; j < this->iSizeField ; j++, key++)
	{
		 std::cout << static_cast<char>(key) << " ";
		 
	}

	std::cout << std::endl;

	int keys = 0;

	

	for (it = cells.begin(); it != cells.end(); it++) {

		std::cout << keys << " ";
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
			default:
				break;
			}

			
		}
		std::cout << std::endl;
		keys++;
	}
	
	std::cout << "  ";
	for (int key = 65, j = 0; j < this->iSizeField; j++, key++)
	{
		std::cout << static_cast<char>(key) << " ";

	}


}

int Field::GetSizeField()
{
	return this->iSizeField;
}

void Field::ChooseCell(std::string cell, Cells & type, Field *field)
{
	std::string coords;
	Cells::position pos;

	char cfirst_letter = toupper(cell[0]);
	const char * cSecond_letter = &cell[1];
	int iFirst_letter = static_cast<int>(cfirst_letter)- 65;
	int iSecond_letter = (atoi(cSecond_letter));

	pos.first = iFirst_letter;
	pos.second = iSecond_letter;

	type.SetPos(pos);
	
	std::cout << std::endl;
	std::cout << "You choosen :  "<<  cfirst_letter << iSecond_letter << std::endl;
	std::cout << "You choosen :  "<< iFirst_letter << iSecond_letter << std::endl;
	/*std::cout << std::endl;
	std::cout << "enter you coords: ";
	std::cin >> coords;
	char cfirst_letter1 = toupper(coords[0]);
	const char* cSecond_letter1 = &coords[1];
	int iFirst_letter1 = static_cast<int>(cfirst_letter1) - 65;
	int iSecond_letter1 = (atoi(cSecond_letter1));
	field->SetCell(iFirst_letter1, iSecond_letter1, type.GetState());
	field->DeleteCell(iFirst_letter, iSecond_letter);*/
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

bool Field::ValidateChoose(Cells::position Pos, Cells cell)
{
		short int limit = 7;
	
		if ((Pos.first >= 0 && Pos.first <= limit) && (Pos.second >= 0 && Pos.second <= limit)) { //сначала проверяем на принадлежность координат полю

			if (this->cells[Pos.second][Pos.first].GetState() != Cells::State::EMPTY && this->cells[Pos.second][Pos.first].GetState() == cell.GetState()){ //проверка на соответствие типа шашки и не пустой клетки

				if (cell.GetState() == Cells::State::WHITE) {

					bool isAttacked = false; // если шашка "под боем"
					bool rightTop = false;
					bool rightBottom = false;
					bool leftTop = false;
					bool leftBottom = false;
					// проверка верхней диагонали справа от шашки
					
					int counter = 1; // длина пути
					bool isMet = false; // встреча на пути вражеской фигуры

					

					while ((Pos.second - counter >= 0) && (Pos.first + counter <=limit)) {
						if (cells[Pos.second - counter][Pos.first + counter].GetState() == Cells::State::EMPTY && counter ==1) {
							rightTop = true;
						}

						if (cells[Pos.second - counter][Pos.first + counter].GetState() == Cells::State::BLACK && counter == 1) {
							isMet = true;

						}

						if ((cells[Pos.second - counter][Pos.first + counter].GetState() == Cells::State::EMPTY && counter == 2) && isMet == true) {
							
							isAttacked = true;
							rightTop = true;
						}
						
						counter++;
					}

					

					// проверка верхней диагонали слева от шашки
					
					counter = 1;
					
					while ((Pos.first - counter >= 0) && (Pos.second - counter >= 0)) {


						if (cells[Pos.second - counter][Pos.first - counter].GetState() == Cells::State::EMPTY && counter == 1) {
							leftTop = true;
						}

						if (cells[Pos.second - counter][Pos.first - counter].GetState() == Cells::State::BLACK && counter == 1) {
							isMet = true;

						}

						if ((cells[Pos.second - counter][Pos.first - counter].GetState() == Cells::State::EMPTY && counter == 2) && isMet == true) {

							isAttacked = true;
							leftTop = true;
						}

						counter++;
					}

					if (leftTop || rightTop)
						return true;
					else
						return false;
				}





				if (cell.GetState() == Cells::State::BLACK) {

					bool isAttacked = false; // если шашка "под боем"
					bool rightTop = false;
					bool rightBottom = false;
					bool leftTop = false;
					bool leftBottom = false;

					// проверка нижней диагонали справа от шашки

					int counter = 1; // длина пути
					bool isMet = false; // встреча на пути вражеской фигуры



					while ((Pos.second + counter <= limit) && (Pos.first + counter <= limit)) {
						if (cells[Pos.second + counter][Pos.first + counter].GetState() == Cells::State::EMPTY && counter == 1) {
							rightBottom = true;
						}

						if (cells[Pos.second + counter][Pos.first + counter].GetState() == Cells::State::WHITE && counter == 1) {
							isMet = true;

						}

						if ((cells[Pos.second + counter][Pos.first + counter].GetState() == Cells::State::EMPTY && counter == 2) && isMet == true) {

							isAttacked = true;
							rightBottom = true;
						}

						counter++;
					}



					// проверка нижней диагонали слева от шашки

					counter = 1;

					while ((Pos.first - counter >= 0) && (Pos.second + counter <= limit)) {


						if (cells[Pos.second + counter][Pos.first - counter].GetState() == Cells::State::EMPTY && counter == 1) {
							leftBottom = true;
						}

						if (cells[Pos.second + counter][Pos.first - counter].GetState() == Cells::State::WHITE && counter == 1) {
							isMet = true;

						}

						if ((cells[Pos.second + counter][Pos.first - counter].GetState() == Cells::State::EMPTY && counter == 2) && isMet == true) {

							isAttacked = true;
							leftBottom = true;
						}

						counter++;
					}

					if (leftBottom || rightBottom)
						return true;
					else
						return false;
				}


			

			
			}
			else return false;
		
			
		
	}
	else
	{
		return false;
	}
		
}

bool Field::ValidateSell(Cells::position endPos, Cells cell, Field* field, Cells::position PrevPos)
{

	short int limit = 7;
	

	int dx = endPos.first - PrevPos.first; 
	int dy = endPos.second - PrevPos.second;


		if ((endPos.first >= 0 && endPos.first <= limit) && (endPos.second >= 0 && endPos.second <= limit)) { //сначала проверяем на принадлежность координат полю

			if (this->cells[endPos.second][endPos.first].GetState() == Cells::State::EMPTY) { //проверка на соответствие типа шашки и не пустой клетки

				

				if (abs(dx) == 2 && abs(dy) == 2) {

					if (this->cells[PrevPos.second + (dy) / 2][PrevPos.first + (dx) / 2].GetState() != cell.GetState() &&
						this->cells[PrevPos.second + (dy) / 2][PrevPos.first + (dx) / 2].GetState() != Cells::State::EMPTY) {

						field->DeleteCell(PrevPos.first, PrevPos.second);
						field->SetCell(endPos.first, endPos.second, cell.GetState());
						field->DeleteCell(PrevPos.first + (dx) / 2, PrevPos.second + (dy) / 2);
						return true;

					}
				}
				else if (abs(dx) == 1 && abs(dy) == 1) {

					field->DeleteCell(PrevPos.first, PrevPos.second);
					field->SetCell(endPos.first, endPos.second, cell.GetState());
					return true;
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
	int iSecond_letter = (atoi(cSecond_letter));

	Cells::position pos = Cells::position(iFirst_letter, iSecond_letter);
	return pos;

}
