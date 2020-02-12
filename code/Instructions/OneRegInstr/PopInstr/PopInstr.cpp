#include "PopInstr.h"


PopInstr::PopInstr(uint line_num) : OneRegInstr(line_num)
{
}

uint32_t PopInstr::GetOpcode()
{
	return 0x1d;
}