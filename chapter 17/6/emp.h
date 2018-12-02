#pragma once

#include <iostream>
#include <string>
#include <fstream>

using std::string;

enum classkind {Employee, Manager, Fink, Highfink};

class abstr_emp
{
private:
	string fname;
	string lname;
	string job;

public:
	abstr_emp();
	abstr_emp(const string & fn, const string & ln, const string & j);
	virtual ~abstr_emp() = 0;			// abstract base class
	virtual void ShowAll() const;
	virtual void SetAll();
	virtual void WriteAll(std::ofstream & ofs) const;
	virtual void GetAll(std::ifstream & ifs);
	friend std::ostream & operator<<(std::ostream & os, const abstr_emp & e);
};

class employee : public abstr_emp
{
public:
	employee();
	employee(const string & fn, const string & ln, const string & j);
	virtual ~employee();
	void ShowAll() const override;
	void SetAll() override;
	void WriteAll(std::ofstream & ofs) const override;
	void GetAll(std::ifstream & ifs) override;
};

class manager : virtual public abstr_emp
{
private:
	int inchargeof;

protected:
	int InChargeOf() const { return inchargeof; }	// output
	int & InChargeOf() { return inchargeof; }		// for assignment

public:
	manager();
	manager(const string & fn, const string ln, const string j, int ico = 0);
	manager(const abstr_emp & e, int ico);
	manager(const manager & m);
	virtual ~manager();
	void ShowAll() const override;
	void SetAll() override;
	void GetAll(std::ifstream & ifs) override;
	void WriteAll(std::ofstream & ofs) const override;
};

class fink : virtual public abstr_emp
{
private:
	string reportsto;

protected:
	const string ReportsTo() const { return reportsto; }	// output
	string & ReportsTo() { return reportsto; }				// for assignment

public:
	fink();
	fink(const string & fn, const string & ln, const string & j, const string & rpo);
	fink(const abstr_emp & e, const string & rpo);
	fink(const fink & e);
	virtual ~fink();
	void ShowAll() const override;
	void SetAll() override;
	void WriteAll(std::ofstream & ofs) const override;
	void GetAll(std::ifstream & ifs) override;
};

class highfink : public manager, public fink
{
public:
	highfink();
	highfink(const string & fn, const string & ln, const string & j, const string & rpo, int ico);
	highfink(const abstr_emp & e, const string & rpo, int ico);
	highfink(const fink & f, int ico);
	highfink(const manager & m, const string & rpo);
	highfink(const highfink & h);
	virtual void ShowAll() const override;
	virtual void SetAll() override;
	void WriteAll(std::ofstream & ofs) const override;
	void GetAll(std::ifstream & ifs) override;
};