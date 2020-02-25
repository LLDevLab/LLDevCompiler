#include "Symbol.h"

Symbol::Symbol(string sym_name, uint sym_pos, ObjFile* obj_file)
{
	this->sym_name = sym_name;
	this->sym_pos = sym_pos;
	this->obj_file = obj_file;
}

string Symbol::GetSymbolName()
{
	return sym_name;
}

uint Symbol::GetSymbolPos()
{
	return sym_pos;
}

uint Symbol::GetSymbolPosOffset()
{
	return obj_file->GetInitBytecodeLineNum();
}

void Symbol::SetSymbolPos(uint sym_pos)
{
	this->sym_pos = sym_pos;
}

string Symbol::GetFileName()
{
	return obj_file->GetFileName();
}

void Symbol::SetSymbolName(string sym_name)
{
	this->sym_name = sym_name;
}

string Symbol::ToString()
{
	const size_t buf_len = 10;
	char buf[buf_len];
	_itoa_s(sym_pos, buf, buf_len, 10);
	string ret = sym_name + '\t' + buf;

	return ret;
}

bool Symbol::operator<(const Symbol& r)
{
	return this->sym_pos < r.sym_pos;
}

bool Symbol::operator>(const Symbol& r)
{
	return this->sym_pos > r.sym_pos;
}

bool Symbol::operator==(const Symbol& r)
{
	return this->sym_pos == r.sym_pos;
}

bool Symbol::operator!=(const Symbol& r)
{
	return this->sym_pos != r.sym_pos;
}

bool Symbol::IsSymbol(string line)
{
	return LineHelper::IsLabel(line) || LineHelper::IsRet(line);
}