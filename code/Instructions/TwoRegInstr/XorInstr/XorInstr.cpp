#include "XorInstr.h"

XorInstr::XorInstr(token_pos pos) : TwoRegInstr(pos)
{
}

uint32_t XorInstr::GetOpcode()
{
	return 0x0f;
}