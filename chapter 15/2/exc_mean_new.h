#pragma once

#include <stdexcept>
#include <iostream>	

using std::logic_error;

class bad_hmean : public logic_error
{
public:
	bad_hmean(const char * c)
		: logic_error(c) { }
};

class bad_gmean : public logic_error
{
public:
	bad_gmean(const char * c)
		: logic_error(c) { }
};
