#pragma once
#include <map>
#include <string>
#include "../ParameterHandler.h"
#include "../../../Exceptions/LLDevExceptions.h"
#include "../../../SupportComponents/SymbolTable/SymbolTable.h"
#include "../../../Types/TypeDef.h"
#include "../../../SupportComponents/Files/Files.h"

using namespace std;

class DbgInfoParamHandler : public ParameterHandler
{
public:
	DbgInfoParamHandler(SymbolTable* symbol_table);
	void GenerateDbgFile(DbgFile file);
private:
	SymbolTable* symbol_table;
};