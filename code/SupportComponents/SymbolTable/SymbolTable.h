#pragma once
#include <string>
#include <map>
#include <vector>
#include <algorithm>
#include <vector>
#include "../Files/Files.h"
#include "../Helpers/LineHelper/LineHelper.h"
#include "../../Exceptions/LLDevExceptions.h"
#include "../../Types/TypeDef.h"
#include "Symbol/Symbols.h"

using namespace std;

class SymbolTable
{
public:
	~SymbolTable();
	void InitSymbolTable(vector<string> file_names);
	bool SymbolExist(string symbol);
	uint GetSymbolPos(string symbol);
	vector<ObjFile*> GetObjFileVector();
	vector<Symbol*> GetFileSymVector(string file_name);
	void SetSymbolPos(string sym_name, uint sym_pos);
private:
	string ReadLine(LdaSrcFile* obj_file);
	void SymbolNotFoundException(string sym_name);
	Symbol* InitSymbol(string line, uint pos, ObjFile* obj_file);

	uint file_names_len;
	map<string, Symbol*> symbols_map;
	map<string, vector<Symbol*>> file_sym_map;
	vector<ObjFile*> obj_file_vector;
};