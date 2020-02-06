#pragma once

#include <iostream>
#include <fstream>
#include <exception>
#include <vector>
#include <string>
#include "../SupportComponents/Helpers/Helpers.h"

using namespace std;

class Compiler
{
public:
	~Compiler();
	void AddFileName(string file_name);
	void Compile();
private:
	void CloseFiles();

	vector<string> obj_file_names;
	ofstream os_hex_file;
	ifstream is_obj_file;
};