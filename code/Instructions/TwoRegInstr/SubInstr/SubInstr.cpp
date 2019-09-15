#include "SubInstr.h"

SubInstr::SubInstr(unsigned int line_num) : TwoRegInstr(line_num)
{
}

uint32_t SubInstr::GetOpcode()
{
	return 0x02;
}