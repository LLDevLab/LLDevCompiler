#pragma once
#include "../Symbol.h"

using namespace std;

class RetSymbol : public Symbol
{
public:
	RetSymbol(string sym_name, uint sym_pos, ObjFile* obj_file);
	virtual symbol_type GetSymbolType();
};