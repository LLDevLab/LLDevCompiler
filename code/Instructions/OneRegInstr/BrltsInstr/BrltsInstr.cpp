#include "BrltsInstr.h"


BrltsInstr::BrltsInstr(token_pos pos) : OneRegInstr(pos)
{
}

uint32_t BrltsInstr::GetOpcode()
{
	return 0x06;
}