#pragma once
#include <string>
#include "../../../Types/TypeDef.h"
#include "../../Files/Files.h"
#include "../../Helpers/LineHelper/LineHelper.h"

using namespace std;

enum symbol_type {SYM_LABEL = 0, SYM_RET = 1, SYM_FUNC = 2};

class Symbol
{
public:
	static bool IsSymbol(string line);

	Symbol(string sym_name, uint sym_pos, ObjFile* obj_file);
	virtual symbol_type GetSymbolType() = 0;
	string GetSymbolName();
	uint GetSymbolPos();
	uint GetFileOffset();
	uint GetSymbolPosOffset();
	string GetFileName();
	virtual string ToString();
	bool operator<(const Symbol& r);
	bool operator>(const Symbol& r);
	bool operator==(const Symbol& r);
	bool operator!=(const Symbol& r);
protected:
	void SetSymbolName(string sym_name);
private:
	string sym_name;
	uint sym_pos;
	ObjFile* obj_file;
};