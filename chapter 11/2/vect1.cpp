#include <cmath>
#include "vect1.h"
using std::sqrt;
using std::sin;
using std::cos;
using std::atan;
using std::atan;
using std::atan2;
using std::cout;

namespace VECTOR
{
	const double RAD_TO_DEG = 45.0 / atan(1.0);

	// private methods
	void Vector::set_x(double mag, double ang)
	{
		x = mag * cos(ang);
	}

	void Vector::set_y(double mag, double ang)
	{
		y = mag * sin(ang);
	}

	// public methods
	Vector::Vector()
	{
		x = y = 0.0;
		mode = RECT;
	}

	Vector::Vector(double n1, double n2, Mode form)
	{
		mode = form;
		if (form == RECT) {
			x = n1;
			y = n2;
		}
		else if (form == POL) {
			set_x(n1, n2 / RAD_TO_DEG);
			set_y(n1, n2 / RAD_TO_DEG);
		}
		else {
			cout << "incorrect mode; all value in the vector object is set to 0.\n";
			cout << "its mode is set to RECT.\n";
			x = y = 0.0;
			mode = RECT;
		}
	}

	void Vector::reset(double n1, double n2, Mode form)
	{
		mode = form;
		if (form == RECT) {
			x = n1;
			y = n2;
		}
		else if (form == POL) {
			set_x(n1, n2 / RAD_TO_DEG);
			set_y(n1, n2 / RAD_TO_DEG);
		}
		else {
			cout << "incorrect mode; all value in the vector object is set to 0.\n";
			cout << "its mode is set to RECT.\n";
			x = y = 0.0;
			mode = RECT;
		}
	}

	Vector::~Vector()		// destructor
	{
		// not using 'new' keyword..
	}

	double Vector::angval() const
	{
		if (x == 0.0 && y == 0.0)
			return 0.0;
		else
			return atan2(y, x);
	}

	void Vector::polar_mode()
	{
		mode = POL;
	}

	void Vector::rect_mode()
	{
		mode = RECT;
	}

	// operator overloading
	Vector Vector::operator+(const Vector & b) const
	{
		return Vector(x + b.x, y + b.y);
	}

	Vector Vector::operator-(const Vector & b) const
	{
		return Vector(x - b.x, y - b.y);
	}

	Vector Vector::operator-() const
	{
		return Vector(-x, -y);
	}

	Vector Vector::operator*(double n) const
	{
		return Vector(n * x, n * y);
	}

	// friend methods
	Vector operator*(double n, const Vector & a)
	{
		return a * n;
	}

	std::ostream & operator<<(std::ostream & os, const Vector & v)
	{
		if (v.mode == Vector::RECT)
			os << "(x, y) = (" << v.x << ", " << v.y << ")";
		else if (v.mode == Vector::POL)
			os << "(m, a) = (" << v.magval() << ", " << v.angval() * RAD_TO_DEG << ")";
		else
			os << "invalid vector object.\n";
		return os;
	}
}  // end of namespace VECTOR