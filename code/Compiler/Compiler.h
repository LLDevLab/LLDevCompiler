#pragma once

#include <iostream>
#include <fstream>
#include <exception>
#include <vector>
#include <string>
#include "../SupportComponents/Helpers/Helpers.h"
#include "../SupportComponents/SymbolTable/SymbolTable.h"
#include "../SupportComponents/Files/Files.h"

using namespace std;

class Compiler
{
public:
	Compiler(ParametersHelper* param_helper);
	~Compiler();
	void AddObjFileToVector(string file_name, uint bytecode_line_num);
	void Compile();
private:
	void ProcessParams();

	vector<ObjFile*> obj_files;
	HexFile* hex_file;
	ParametersHelper* param_helper;
};