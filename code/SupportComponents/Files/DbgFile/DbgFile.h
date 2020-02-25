#pragma once
#include "../File.h"

using namespace std;

class DbgFile : public File
{
public:
	DbgFile(string file_name) : File(file_name) {};
	virtual string GetFileExtension();
};