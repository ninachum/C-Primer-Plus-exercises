#pragma once

class Cd
{
private:
	char * performers;
	char * label;
	int selections;
	double playtime;

public:	
	Cd(const char * s1, const char * s2, int n, double x);
	Cd(const Cd & c);
	Cd();
	virtual ~Cd();
	virtual void Report() const;
	Cd & operator=(const Cd & d);
};

class Classic : public Cd
{
private:
	char * title;

public:
	Classic(const char * songname, const char * s1, const char * s2, int n, double x);
	Classic(const Classic & c);
	Classic();
	virtual ~Classic();
	virtual void Report() const;
	Classic & operator=(const Classic & c);
};