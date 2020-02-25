#pragma once
#include "../Parameter.h"
#include "../../../SupportComponents/SymbolTable/SymbolTable.h"

using namespace std;

class DbgInfoParam : public Parameter
{
public:
	DbgInfoParam(string param, SymbolTable* symbol_table);
	virtual param_type GetParameterType();
};