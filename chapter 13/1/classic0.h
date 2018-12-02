#pragma once

class Cd
{
private:
	char performers[50];
	char label[20];
	int selections;
	double playtime;

public:	
	Cd(const char * s1, const char * s2, int n, double x);
	Cd();
	virtual ~Cd();
	virtual void Report() const;
	Cd & operator=(const Cd & d);
};

class Classic : public Cd
{
private:
	char title[50];

public:
	Classic(const char * songname, const char * s1, const char * s2, int n, double x);
	Classic();
	virtual void Report() const;
};