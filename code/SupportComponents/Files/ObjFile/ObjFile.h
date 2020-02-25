#pragma once
#include "../File.h"

class ObjFile : public File
{
public:
	ObjFile(string file_name, uint init_bytecode_line_num);
	virtual string GetFileExtension();
	uint GetInitBytecodeLineNum();
	bool operator<(const ObjFile& r);
	bool operator>(const ObjFile& r);
	bool operator==(const ObjFile& r);
private:
	uint init_bytecode_line_num;
};