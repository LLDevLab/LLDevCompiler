#pragma once

#include <exception>
#include <string>
#include "../LLDevException.h"

using namespace std;

class LLDevParameterException :
	public LLDevException
{
public:
	explicit LLDevParameterException(const string& msg);

	virtual const char* what();
private:
	string message;
};