#include "SubInstr.h"

SubInstr::SubInstr(token_pos pos) : TwoRegInstr(pos)
{
}

uint32_t SubInstr::GetOpcode()
{
	return 0x02;
}