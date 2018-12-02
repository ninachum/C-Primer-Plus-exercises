#pragma once

#include <string>

using std::string;

class Person
{
private:
	string first;
	string last;

protected:
	virtual void Data() const;
	virtual void Get();

public:
	Person(const string & f = "John", const string & l = "Doe")
		: first(f), last(l) { }
	virtual ~Person() { };
	virtual void Show() const;
	virtual void Set();

};

class Gunslinger : virtual public Person
{
private:
	double pullingTime;
	int notch;

protected:
	virtual void Data() const;
	virtual void Get();

public:
	Gunslinger(const string & f = "John", const string & l = "Doe", double pt = 0.38, int nh = 10)
		: Person(f, l), pullingTime(pt), notch(nh) { }
	Gunslinger(const Person & p, double pt = 0.38, int nh = 10)
		: Person(p), pullingTime(pt), notch(nh) { }
	virtual ~Gunslinger() { };
	virtual void Show() const;
	double Draw() const;
	virtual void Set();

};

class PokerPlayer : virtual public Person
{
private:

protected:
	virtual void Data() const;
	virtual void Get();

public:
	PokerPlayer(const string & f = "John", const string & l = "Doe")
		: Person(f, l) { }
	PokerPlayer(const Person & p)
		: Person(p) { }
	virtual ~PokerPlayer() { };
	int Draw() const;
	virtual void Show() const;
	virtual void Set();

};

class BadDude : public Gunslinger, public PokerPlayer
{
private:

protected:
	virtual void Data() const;
	virtual void Get();

public:
	BadDude(const string & f = "John", const string & l = "Doe", double pt = 0.38, int nh = 10)
		: Person(f, l), Gunslinger(f, l, pt, nh), PokerPlayer(f, l) { }
	virtual ~BadDude() { };
	double Gdraw() const;
	int Cdraw() const;
	virtual void Show() const;
	virtual void Set();
};