#pragma once
#include <string>
#include <map>
#include <iostream>
#include <fstream>
#include "../Helpers/Helpers.h"
#include "../../Exceptions/LLDevExceptions.h"

using namespace std;

class SymbolTable
{
public:
	SymbolTable(int argc, char* argv[]);
	~SymbolTable();
	void InitSymbolTable();
	bool LabelExist(string label);
	int GetLabelLineNum(string label);
private:
	int file_names_len;
	string* file_names;
	map<string, int> label_to_line_num_map;
	ifstream ios_file;

	void OpenFile(string file_name);
	void CloseFile();
	string ReadLine();
};