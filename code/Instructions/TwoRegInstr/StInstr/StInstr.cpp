#include "StInstr.h"

StInstr::StInstr(token_pos pos) : TwoRegInstr(pos)
{
}

uint32_t StInstr::GetOpcode()
{
	return 0x1a;
}