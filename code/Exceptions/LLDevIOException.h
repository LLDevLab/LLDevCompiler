#pragma once

#include <exception>
#include <string>

using namespace std;

class LLDevIOException :
	public exception
{
public:
	explicit LLDevIOException(const string& msg);

	virtual const char* what();
private:
	string message;
};

