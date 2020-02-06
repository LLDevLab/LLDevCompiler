#pragma once

#include <exception>
#include <string>

using namespace std;

class LLDevException :
	public exception
{
public:
	virtual const char* what() = 0;
private:
	string message;
};