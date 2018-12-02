#pragma once

#include <iostream>

using std::cout;
using std::endl;

class Remote;

class Tv
{
private:
	int state;
	int volume;
	int maxchannel;
	int channel;
	int mode;
	int input;

public:
	friend class Remote; // Remote can access private members of Tv.
	enum { Off, On };
	enum { MinVal, MaxVal = 20 };
	enum { Antenna, Cable };
	enum { TV, DVD };

	Tv(int s = Off, int mc = 125)
		: state(s), volume(5), maxchannel(mc), channel(2), mode(Cable), input(TV)
	{ }
	void onoff() { state = (state == On) ? Off : On; }
	bool ison() const { return state == On; }
	bool volup();
	bool voldown();
	void chanup();
	void chandown();
	void set_mode() { mode = (mode == Antenna) ? Cable : Antenna; }
	void set_input() { input = (input == TV) ? DVD : TV; }
	void settings() const;	// print all current settings
	void change_mod(Remote & r) const;
};

class Remote
{
public:
	enum cmode { GENERAL, INTERACTIVE };

private:
	int mode;
	cmode mod;

public:
	Remote(int m = Tv::TV, cmode x = GENERAL)
		: mode(m), mod(x)
	{ }
	friend class Tv;
	bool volup(Tv & t) { return t.volup(); }
	bool voldown(Tv & t) { return t.voldown(); }
	void onoff(Tv & t) { t.onoff(); }
	void chanup(Tv & t) { t.chanup(); }
	void chandown(Tv & t) { t.chandown(); }
	void set_chan(Tv & t, int c) { t.channel = c; }
	void set_mode(Tv & t) { t.set_mode(); }
	void set_input(Tv & t) { t.set_input(); }
	void print_mod() const;
};
