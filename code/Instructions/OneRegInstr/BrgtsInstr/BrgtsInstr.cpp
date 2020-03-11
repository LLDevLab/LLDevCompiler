#include "BrgtsInstr.h"


BrgtsInstr::BrgtsInstr(token_pos pos) : OneRegInstr(pos)
{
}

uint32_t BrgtsInstr::GetOpcode()
{
	return 0x07;
}