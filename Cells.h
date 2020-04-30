#pragma once
#include <utility>



class Cells
{
public:
	typedef std::pair<int, int> position; //координаты фигуры
	enum class State { EMPTY, WHITE, BLACK, QUEEN_W, QUEEN_B };
	State GetState() { return this->Fstate; };
	void SetState(State state) { this->Fstate = state; };
	const int & GetPosX() { return this->pos.first; };
	const int & GetPosY() { return this->pos.second; };
	const position& GetPos() { return this->pos; };
	void SetPos(const position& pos) { this->pos = pos;};
	Cells(/*const position & position,*/ State state);
	Cells();
	~Cells();

private:
	State Fstate;
	position pos;
};

