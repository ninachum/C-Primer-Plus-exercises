#include "emp.h"

using std::cout;
using std::endl;
using std::cin;
using std::getline;

abstr_emp::abstr_emp()
	: fname("unnamed fname"), lname("unnamed lname"), job("not assigned")
{ }

abstr_emp::abstr_emp(const string & fn, const string & ln, const string & j)
	: fname(fn), lname(ln), job(j)
{ }

abstr_emp::~abstr_emp()
{ }

void abstr_emp::ShowAll() const
{
	cout << "first name : " << fname << endl;
	cout << "last name  : " << lname << endl;
	cout << "job        : " << job << endl;
}

void abstr_emp::SetAll()
{
	cout << "first name ? ";
	getline(cin, fname);
	cout << "last name ? ";
	getline(cin, lname);
	cout << "job ? ";
	getline(cin, job);
}

std::ostream & operator<<(std::ostream & os, const abstr_emp & e)
{
	e.ShowAll();
	return os;
}

employee::employee()
	: abstr_emp()
{ }

employee::employee(const string & fn, const string & ln, const string & j)
	: abstr_emp(fn, ln, j)
{ }

employee::~employee()
{ }

void employee::ShowAll() const
{
	abstr_emp::ShowAll();
}

void employee::SetAll()
{
	abstr_emp::SetAll();
}

manager::manager()
	: abstr_emp(), inchargeof(0)
{ }

manager::manager(const string & fn, const string ln, const string j, int ico)
	: abstr_emp(fn, ln, j), inchargeof(ico)
{ }

manager::manager(const abstr_emp & e, int ico)
	: abstr_emp(e), inchargeof(ico)
{ }

manager::manager(const manager & m)
	: abstr_emp(m), inchargeof(m.InChargeOf())
{ }

manager::~manager()
{ }

void manager::ShowAll() const
{
	abstr_emp::ShowAll();
	cout << "in charge of " << inchargeof << " employees." << endl;
}

void manager::SetAll()
{
	abstr_emp::SetAll();
	cout << "in charge of ? : ";
	cin >> inchargeof;
	while (cin.get() != '\n')
		continue;
}

fink::fink()
	: abstr_emp(), reportsto("unnamed reportsto")
{ }

fink::fink(const string & fn, const string & ln, const string & j, const string & rpo)
	: abstr_emp(fn, ln, j), reportsto(rpo)
{ }

fink::fink(const abstr_emp & e, const string & rpo)
	: abstr_emp(e), reportsto(rpo)
{ }

fink::fink(const fink & e)
	: abstr_emp(e)
{ }

fink::~fink()
{ }

void fink::ShowAll() const
{
	abstr_emp::ShowAll();
	cout << "this employee reports to : " << reportsto << endl;
}

void fink::SetAll()
{
	abstr_emp::SetAll();
	cout << "reports to who ? : ";
	getline(cin, reportsto);
}

highfink::highfink()
	: abstr_emp(), manager(), fink()
{ }

highfink::highfink(const string & fn, const string & ln, const string & j, const string & rpo, int ico)
	: abstr_emp(fn, ln, j), manager(fn, ln, j, ico), fink(fn, ln, j, rpo)
{ }

highfink::highfink(const abstr_emp & e, const string & rpo, int ico)
	: abstr_emp(e), manager(e, ico), fink(e, rpo)
{ }

highfink::highfink(const fink & f, int ico)
	: abstr_emp(f), manager(f, ico), fink(f)
{ }

highfink::highfink(const manager & m, const string & rpo)
	: abstr_emp(m), manager(m), fink(m, rpo)
{ }

highfink::highfink(const highfink & h)
	: abstr_emp(h), manager(h), fink(h)
{ }

void highfink::ShowAll() const
{
	abstr_emp::ShowAll();
	cout << "in charge of " << manager::InChargeOf() << " employees." << endl;
	cout << "this employee reports to : " << fink::ReportsTo() << endl;
}

void highfink::SetAll()
{
	abstr_emp::SetAll();
	cout << "reports to who ? : ";
	getline(cin, fink::ReportsTo());
	cout << "in charge of ? : ";
	cin >> manager::InChargeOf();
	while (cin.get() != '\n')
		continue;
}