#include "PopInstr.h"


PopInstr::PopInstr(token_pos pos) : OneRegInstr(pos)
{
}

uint32_t PopInstr::GetOpcode()
{
	return 0x1d;
}