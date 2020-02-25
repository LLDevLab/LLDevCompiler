#include "ObjFile.h"

#define OBJ_FILE_EXT ".o"

ObjFile::ObjFile(string file_name, uint init_bytecode_line_num) :
	File(file_name)
{
	this->init_bytecode_line_num = init_bytecode_line_num;
}

string ObjFile::GetFileExtension()
{
	return OBJ_FILE_EXT;
}

uint ObjFile::GetInitBytecodeLineNum()
{
	return init_bytecode_line_num;
}

bool ObjFile::operator<(const ObjFile& r)
{
	return this->init_bytecode_line_num < r.init_bytecode_line_num;
}

bool ObjFile::operator>(const ObjFile& r)
{
	return this->init_bytecode_line_num > r.init_bytecode_line_num;
}

bool ObjFile::operator==(const ObjFile& r)
{
	return this->init_bytecode_line_num == r.init_bytecode_line_num;
}