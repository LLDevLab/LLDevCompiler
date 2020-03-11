#include "BrneInstr.h"


BrneInstr::BrneInstr(token_pos pos) : OneRegInstr(pos)
{
}

uint32_t BrneInstr::GetOpcode()
{
	return 0x05;
}