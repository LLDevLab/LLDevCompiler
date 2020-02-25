#pragma once
#include "../Symbol.h"

using namespace std;

class LabelSymbol : public Symbol
{
public:
	LabelSymbol(string sym_name, uint sym_pos, ObjFile* obj_file) : Symbol(sym_name, sym_pos, obj_file) {};
	virtual symbol_type GetSymbolType();
};