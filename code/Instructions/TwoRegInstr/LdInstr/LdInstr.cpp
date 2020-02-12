#include "LdInstr.h"

LdInstr::LdInstr(uint line_num) : TwoRegInstr(line_num)
{
}

uint32_t LdInstr::GetOpcode()
{
	return 0x19;
}