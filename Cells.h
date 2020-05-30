#pragma once
#include <utility>



class Cells
{
public:
	typedef std::pair<int, int> position; //координаты фигуры
	enum class State { EMPTY, WHITE, BLACK, QUEEN_W, QUEEN_B };
	enum class isCutting {NO , YES};
	State GetState() { return this->Fstate; };
	void SetState(State state) { this->Fstate = state; };
	const position& GetPos() { return this->pos; };
	void SetPos(const position& pos) { this->pos = pos;};
	isCutting GetCutt() { return this->cutt; };
	void SetCutt(isCutting t) { this->cutt = t; };
	Cells(State state);
	Cells();
	~Cells();

private:
	State Fstate;
	position pos;
	isCutting cutt;
};

