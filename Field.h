#pragma once
#include "PCH.h"
#include <vector>



class Field
{
private:
	
	DWORD iSizeField; //������ ����
	std::vector <std::vector <Cells>> cells; //��������� ����
	std::vector <std::vector <Cells>> ::iterator it; //��������
	std::vector <Cells>::iterator i; //��������
	bool isAttackedWhite; //��� � �����
	bool isAttackedBlack; //��� � ������
	Cells mas[24];
public: 
	Field();
	void CreateField();						/*������� ���� ������� iSizeField*/
	void SetSizeField(const int size);		/*������ ����*/
	void DrawField();						/*����������� ����*/
	int GetSizeField();						/*��������� ������� ����*/
	void ChooseCell(std::string s, Cells & cell,Field* field);   /*������� ������*/
	void DeleteCell(WORD xPos, WORD yPos);
	void SetCell(WORD xPos, WORD yPos, Cells::State cell); /*������������� ������ �� ������*/
	bool ValidateChoose(Cells::position Pos, Cells cellPawn, Cells cellQueen); /*�������� �� ����������� ����*/
	bool ValidateSell(Cells::position endPos , Cells cellPawn,Cells cellQueen, Field* field, Cells::position PrevPos); /*�������� ����*/
	Cells::position CoordPerform(std::string s); //�������������� ��������� �� ������ � ���� ����� �����
	bool CheckCondition(Cells cell, Cells::position Pos, short int limit);
	bool CheckWhite(Cells cell, Cells::position Pos, short int limit);
	bool CheckWhiteQueen(Cells cell, Cells::position Pos, short int limit);
	bool CheckBlack(Cells cell, Cells::position Pos, short int limit);
	bool CheckBlackQueen(Cells cell, Cells::position Pos, short int limit);
	void CheckSteps();
	void QueenMade();

};
