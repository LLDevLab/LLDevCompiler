#include "LLDevSymbolTableException.h"

LLDevSymbolTableException::LLDevSymbolTableException(const string& msg)
{
	message = msg;
}

const char* LLDevSymbolTableException::what()
{
	return message.c_str();
}
