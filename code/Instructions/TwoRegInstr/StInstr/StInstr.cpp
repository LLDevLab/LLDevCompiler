#include "StInstr.h"

StInstr::StInstr(uint line_num) : TwoRegInstr(line_num)
{
}

uint32_t StInstr::GetOpcode()
{
	return 0x1a;
}