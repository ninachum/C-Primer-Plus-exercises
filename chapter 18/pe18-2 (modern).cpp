#include <string>
#include <iostream>
#include <memory>
#include <utility>

using std::cout;

class Cpmv
{
public:
	struct Info
	{
		std::string qcode;
		std::string zcode;
		Info()   {}
		Info(std::string q, std::string z) : qcode(q), zcode(z) {}
	};

private:
	std::unique_ptr<Info> pi;
public:
	Cpmv()
	{
		cout << "default constructor called " << '\n';
		pi = std::make_unique<Info>();
	}

	Cpmv(std::string q, std::string z)
	{
		cout << "2-string constructor called " << '\n';
		pi = std::make_unique<Info>(q, z);
	}

	Cpmv(const Cpmv & cp)
	{
		cout << "copy constructor called " << '\n';
		pi = std::make_unique<Info>(cp.pi->qcode, cp.pi->zcode);
	}

	Cpmv(Cpmv && mv)
	{
		cout << "move constructor called " << '\n';
		pi = std::move(mv.pi);
	}

	~Cpmv()
	{
		cout << "destructor called " << '\n';
		cout << "memory area pointed by pi will be released automatically.\n";
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
		pi = std::move(mv.pi);
		return *this;
	}
	Cpmv operator+(const Cpmv & obj) const
	{
		cout << "plus operator called " << '\n';
		return Cpmv(pi->qcode + obj.pi->qcode, pi->zcode + obj.pi->zcode);
	}
	void Display() const
	{
		cout << "addr. of pi = " << pi << '\n';
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