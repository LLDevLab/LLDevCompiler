#include "CmpInstr.h"

CmpInstr::CmpInstr(token_pos pos) : TwoRegInstr(pos)
{
}

uint32_t CmpInstr::GetOpcode()
{
	return 0x0a;
}