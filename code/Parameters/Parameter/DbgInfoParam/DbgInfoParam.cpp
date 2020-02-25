#include "DbgInfoParam.h"

DbgInfoParam::DbgInfoParam(string param, SymbolTable* symbol_table) : Parameter(param)
{
	handler = new DbgInfoParamHandler(symbol_table);
};