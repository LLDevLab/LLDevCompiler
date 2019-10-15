#include "LdInstr.h"

LdInstr::LdInstr(unsigned int line_num) : TwoRegInstr(line_num)
{
}

uint32_t LdInstr::GetOpcode()
{
	return 0x19;
}