#pragma once

#include <iostream>

namespace VECTOR
{
	class Vector
	{
	public:
		enum Mode {	RECT, POL }; // RECT mode, POLAR mode
	private:
		double x;
		double y;
		Mode mode;

		void set_x(double mag, double ang);
		void set_y(double mag, double ang);
	public:
		Vector();
		Vector(double n1, double n2, Mode form = RECT);
		void reset(double n1, double n2, Mode form = RECT);
		~Vector();
		double xval() const { return x; }
		double yval() const { return y; }
		double magval() const { return sqrt(x * x + y * y); }
		double angval() const;	
		void polar_mode();		// set mode to polar mode
		void rect_mode();		// set mode to rect mode
		// Operator overloading
		Vector operator+(const Vector & b) const;
		Vector operator-(const Vector & b) const;
		Vector operator-() const;
		Vector operator*(double n) const;
		// Friend function
		friend Vector operator*(double n, const Vector & a);
		friend std::ostream &
			operator<<(std::ostream & os, const Vector & v);
	};
} // end of namespace VECTOR