#pragma once

#include <exception>
#include <string>
#include "../LLDevException.h"

using namespace std;

class LLDevSymbolTableException :
	public LLDevException
{
public:
	explicit LLDevSymbolTableException(const string& msg);

	virtual const char* what();
private:
	string message;
};

