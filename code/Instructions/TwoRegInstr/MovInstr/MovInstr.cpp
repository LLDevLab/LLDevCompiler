#include "MovInstr.h"

MovInstr::MovInstr(unsigned int line_num) : TwoRegInstr(line_num)
{
}

uint32_t MovInstr::GetOpcode()
{
	return 0x1b;
}