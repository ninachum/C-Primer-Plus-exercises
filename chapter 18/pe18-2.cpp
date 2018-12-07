#include <string>
#include <iostream>

using std::cout;

class Cpmv
{
public:
	struct Info
	{
		std::string qcode;
		std::string zcode;
	};

private:
	Info *pi;
public:
	Cpmv()
	{
		cout << "default constructor called " << '\n';
		pi = new Info;
	}

	Cpmv(std::string q, std::string z)
	{
		cout << "2-string constructor called " << '\n';
		pi = new Info;
		pi->qcode = q;
		pi->zcode = z;
	}

	Cpmv(const Cpmv & cp)
	{
		cout << "copy constructor called " << '\n';
		pi = new Info;
		pi->qcode = cp.pi->qcode;
		pi->zcode = cp.pi->zcode;
	}

	Cpmv(Cpmv && mv)
	{
		cout << "move constructor called " << '\n';
		pi = new Info;
		pi = mv.pi;
		mv.pi = nullptr;
	}

	~Cpmv()
	{
		cout << "destructor called " << '\n';
		delete pi;
	}

	Cpmv & operator=(const Cpmv & cp)
	{
		cout << "copy assignement called " << '\n';
		if (this == &cp)
			return *this;
		pi->qcode = cp.pi->qcode;
		pi->zcode = cp.pi->zcode;
		return *this;
	}

	Cpmv & operator=(Cpmv && mv)
	{
		cout << "move assignment called " << '\n';
		if (this == &mv)
			return *this;
		pi = mv.pi;
		mv.pi = nullptr;
		return *this;
	}
	Cpmv operator+(const Cpmv & obj) const
	{
		cout << "plus operator called " << '\n';
		return Cpmv(pi->qcode + obj.pi->qcode, pi->zcode + obj.pi->zcode);
	}
	void Display() const
	{
		cout << "addr. of pi = " << (void *)pi << '\n';
		cout << "qcode : " << pi->qcode << '\n';
		cout << "zcode : " << pi->zcode << '\n';
	}
};

int main()
{
	using std::string;
	Cpmv x1;
	Cpmv x2("chool", "tarsette");
	Cpmv x3("nina", "chum");

	x1 = x2;
	x1 = x2 + x3;

	Cpmv x4 = x1;
	return 0;
}