#include "Parameter.h"

Parameter::Parameter(string param)
{
	this->param = param;
}

Parameter::~Parameter()
{
	delete handler;
}

string Parameter::GetParameterName()
{
	return param;
}

ParameterHandler* Parameter::GetHandler()
{
	return handler;
}