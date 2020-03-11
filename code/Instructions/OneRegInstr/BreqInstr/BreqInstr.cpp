#include "BreqInstr.h"


BreqInstr::BreqInstr(token_pos pos) : OneRegInstr(pos)
{
}

uint32_t BreqInstr::GetOpcode()
{
	return 0x04;
}