#pragma once
#include "PCH.h"
#include <vector>



class Field
{
private:
	
	DWORD iSizeField; //размер поля
	std::vector <std::vector <Cells>> cells; //контейнер поля
	std::vector <std::vector <Cells>> ::iterator it; //итератор
	std::vector <Cells>::iterator i; //итератор
	
public: 
	int countTryBlack; // продолжительность хода белых 
	int countTryWhite; // продолжительность хода у черных
	bool isAttackedWhite; //бой у белых
	bool isAttackedBlack; //бой у черных
	bool whiteWin{ false };
	bool blackWin{ false };
	bool isEated{ false };
	Field();
	void CreateField();						/*Создает поле размера iSizeField*/
	void SetSizeField(const int size);		/*Размер поля*/
	void DrawField();						/*Отображение поля*/
	int GetSizeField();						/*Получение размера поля*/
	void DeleteCell(WORD xPos, WORD yPos);
	void SetCell(WORD xPos, WORD yPos, Cells::State cell); /*установливает фигуру на клетку*/
	bool ValidateChoose(Cells::position Pos, Cells cellPawn, Cells cellQueen); /*проверка на возможность хода*/
	bool ValidateSell(Cells::position endPos , Cells cellPawn,Cells cellQueen, Field* field, Cells::position PrevPos); /*проверка хода*/
	Cells::position CoordPerform(std::string s); //преобразование координат из строки в пару целых чисел
	bool CheckCondition(Cells cell, Cells::position Pos, short int limit); // общая проверка на возможность хода
	bool CheckWhite(Cells cell, Cells::position Pos, short int limit); // проверка возможности хода у белых шашек
	bool CheckWhiteQueen(Cells cell, Cells::position Pos, short int limit); // проверка возможности хода у белых дамок
	bool CheckBlack(Cells cell, Cells::position Pos, short int limit); // проверка возможности хода у черных шашек
	bool CheckBlackQueen(Cells cell, Cells::position Pos, short int limit); // проверка возможности хода у черных дамок
	void CheckSteps(); // проверка на "бой"
	void QueenMade(); // преобразование пешки в дамку
	bool Victory(); // проверка на победу

};
