#include "LLDevIOException.h"



LLDevIOException::LLDevIOException(const string& msg)
{
	message = msg;
}

const char* LLDevIOException::what()
{
	return message.c_str();
}
