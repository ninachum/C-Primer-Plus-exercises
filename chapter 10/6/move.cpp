#include "move.h"
#include <iostream>

Move::Move(double a, double b)
{
	x = a;
	y = b;
}
void Move::showmove() const
{
	using std::cout;
	cout << "x is " << x << ", and y is " << y << "." << std::endl;
}
Move Move::add(const Move & m) const
{
	Move returning(x + m.x, y + m.y);
	return returning;
}

void Move::reset(double a, double b)
{
	x = a;
	y = b;
}