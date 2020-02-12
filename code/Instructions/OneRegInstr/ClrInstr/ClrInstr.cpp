#include "ClrInstr.h"


ClrInstr::ClrInstr(uint line_num) : OneRegInstr(line_num)
{
}

uint32_t ClrInstr::GetOpcode()
{
	return 0x0b;
}