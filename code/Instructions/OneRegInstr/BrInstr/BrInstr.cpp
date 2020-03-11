#include "BrInstr.h"


BrInstr::BrInstr(token_pos pos) : OneRegInstr(pos)
{
}

uint32_t BrInstr::GetOpcode()
{
	return 0x03;
}