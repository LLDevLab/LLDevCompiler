#include "MovInstr.h"

MovInstr::MovInstr(token_pos pos) : TwoRegInstr(pos)
{
}

uint32_t MovInstr::GetOpcode()
{
	return 0x1b;
}