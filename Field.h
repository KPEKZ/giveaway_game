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
	bool isAttackedWhite; //бой у белых
	bool isAttackedBlack; //бой у черных
	Cells mas[24];
public: 
	Field();
	void CreateField();						/*Создает поле размера iSizeField*/
	void SetSizeField(const int size);		/*Размер поля*/
	void DrawField();						/*Отображение поля*/
	int GetSizeField();						/*Получение размера поля*/
	void ChooseCell(std::string s, Cells & cell,Field* field);   /*выбрать фигуру*/
	void DeleteCell(WORD xPos, WORD yPos);
	void SetCell(WORD xPos, WORD yPos, Cells::State cell); /*установливает фигуру на клетку*/
	bool ValidateChoose(Cells::position Pos, Cells cellPawn, Cells cellQueen); /*проверка на возможность хода*/
	bool ValidateSell(Cells::position endPos , Cells cellPawn,Cells cellQueen, Field* field, Cells::position PrevPos); /*проверка хода*/
	Cells::position CoordPerform(std::string s); //преобразование координат из строки в пару целых чисел
	bool CheckCondition(Cells cell, Cells::position Pos, short int limit);
	bool CheckWhite(Cells cell, Cells::position Pos, short int limit);
	bool CheckWhiteQueen(Cells cell, Cells::position Pos, short int limit);
	bool CheckBlack(Cells cell, Cells::position Pos, short int limit);
	bool CheckBlackQueen(Cells cell, Cells::position Pos, short int limit);
	void CheckSteps();
	void QueenMade();

};
