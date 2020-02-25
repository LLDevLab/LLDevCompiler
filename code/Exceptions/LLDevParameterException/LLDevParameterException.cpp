#include "LLDevParameterException.h"

LLDevParameterException::LLDevParameterException(const string& msg)
{
	message = msg;
}

const char* LLDevParameterException::what()
{
	return message.c_str();
}