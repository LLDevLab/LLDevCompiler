#include "RetSymbol.h"

RetSymbol::RetSymbol(string sym_name, uint sym_pos, ObjFile* obj_file) :
	Symbol(sym_name, sym_pos, obj_file)
{
	const size_t buf_len = 10;
	char buf[buf_len];
	_itoa_s(sym_pos, buf, buf_len, 10);

	string ret_sym_name = sym_name + '_' + buf;
	SetSymbolName(ret_sym_name);
}

symbol_type RetSymbol::GetSymbolType()
{
	return SYM_RET;
}