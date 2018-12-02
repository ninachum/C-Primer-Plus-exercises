#pragma once

class Golf {

private:
	static const int LEN = 40;
	char fullname[LEN];
	int handicap;
public:
	Golf(const char * name, int hc);
	Golf();
	void sethandicap(int hc);
	void showgolf() const;
};
