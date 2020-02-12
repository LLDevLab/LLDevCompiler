#include "SubcInstr.h"

SubcInstr::SubcInstr(uint line_num) : TwoRegInstr(line_num)
{
}

uint32_t SubcInstr::GetOpcode()
{
	return 0x18;
}