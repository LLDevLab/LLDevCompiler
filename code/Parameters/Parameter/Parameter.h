#pragma once
#include <string>
#include "../../ParameterHandlers/ParameterHandlers.h"

using namespace std;

enum param_type {PARAM_DBG_INFO = 0};

// Parameter classes will hold different information about parameters 
// as well as parameter's handler class, where is actual logic for handling parameter will be located
class Parameter
{
public:
	string GetParameterName();
	virtual param_type GetParameterType() = 0;
	ParameterHandler* GetHandler();
	~Parameter();
protected:
	Parameter(string param);
	ParameterHandler* handler;
private:
	string param;
};