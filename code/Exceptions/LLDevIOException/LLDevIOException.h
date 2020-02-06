#pragma once

#include <exception>
#include <string>
#include "../LLDevException.h"

using namespace std;

class LLDevIOException :
	public LLDevException
{
public:
	explicit LLDevIOException(const string& msg);

	virtual const char* what();
private:
	string message;
};

