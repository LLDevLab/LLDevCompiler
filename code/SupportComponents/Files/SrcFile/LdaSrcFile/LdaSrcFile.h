#pragma once
#include "../../File.h"

using namespace std;

class LdaSrcFile : public File
{
public:
	LdaSrcFile(string file_name) : File(file_name) {};
	virtual string GetFileExtension();
};