#pragma once

class Plorg
{
private:
	static const int LEN = 20;
	char name[LEN];
	int CI;
public:
	Plorg(const char * s = "Plorga");
	void show() const;
};