#include "SubcInstr.h"

SubcInstr::SubcInstr(token_pos pos) : TwoRegInstr(pos)
{
}

uint32_t SubcInstr::GetOpcode()
{
	return 0x18;
}