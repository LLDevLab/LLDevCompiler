#pragma once
#include "../File.h"

using namespace std;

class HexFile : public File
{
public:
	HexFile(string file_name) : File(file_name) {};
	virtual string GetFileExtension();
};