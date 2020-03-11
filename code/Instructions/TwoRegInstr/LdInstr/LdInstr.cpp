#include "LdInstr.h"

LdInstr::LdInstr(token_pos pos) : TwoRegInstr(pos)
{
}

uint32_t LdInstr::GetOpcode()
{
	return 0x19;
}