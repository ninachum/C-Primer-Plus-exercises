#pragma once

#include <iostream>

class DMA
{
private:
	char * label;
	int rating;

public:
	DMA(const char * l = "null", int r = 0);
	DMA(const DMA & rs);	// copy constructor
	virtual ~DMA();				// virtual destructor
	DMA & operator=(const DMA & rs);	// assignment operator
	virtual void view() const = 0;
	friend std::ostream & operator<<(std::ostream & os, const DMA & rs);
};

class baseDMA : public DMA
{
private:
		
public:
	baseDMA(const char * l = "null", int r = 0);
	virtual void view() const;
};

class lacksDMA : public DMA
{
private:
	enum { COL_LEN = 40 };
	char color[COL_LEN];

public:
	lacksDMA(const char * c = "blank", const char * l = "null", int r = 0);
	lacksDMA(const char * c, const DMA & rs);
	virtual void view() const;
	friend std::ostream & operator<<(std::ostream & os, const lacksDMA & ls);
};

class hasDMA : public DMA
{
private:
	char * style;

public:
	hasDMA(const char * s = "none", const char * l = "null", int r = 0);
	hasDMA(const char * s, const DMA & rs);
	hasDMA(const hasDMA & hs);
	~hasDMA();
	hasDMA & operator=(const hasDMA & rs);
	virtual void view() const;
	friend std::ostream & operator<<(std::ostream & os, const hasDMA & rs);
};