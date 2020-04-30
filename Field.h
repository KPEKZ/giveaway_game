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
public:
	Field();
	void CreateField();						/*������� ���� ������� iSizeField*/
	void SetSizeField(const int size);		/*������ ����*/
	void DrawField();						/*����������� ����*/
	int GetSizeField();						/*��������� ������� ����*/
	void ChooseCell(std::string s, Cells & cell,Field* field);   /*������� ������*/
	void DeleteCell(WORD xPos, WORD yPos);
	void SetCell(WORD xPos, WORD yPos, Cells::State cell); /*������������� ������ �� ������*/
	bool ValidateChoose(Cells::position Pos, Cells cell); /*�������� �� ����������� ����*/
	bool ValidateSell(Cells::position endPos , Cells cell, Field* field, Cells::position PrevPos); /*�������� ����*/
	Cells::position CoordPerform(std::string s); //�������������� ��������� �� ������ � ���� ����� �����

};
