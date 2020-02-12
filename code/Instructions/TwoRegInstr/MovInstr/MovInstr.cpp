#include "MovInstr.h"

MovInstr::MovInstr(uint line_num) : TwoRegInstr(line_num)
{
}

uint32_t MovInstr::GetOpcode()
{
	return 0x1b;
}