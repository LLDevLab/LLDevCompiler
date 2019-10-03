#include "SubcInstr.h"

SubcInstr::SubcInstr(unsigned int line_num) : TwoRegInstr(line_num)
{
}

uint32_t SubcInstr::GetOpcode()
{
	return 0x18;
}