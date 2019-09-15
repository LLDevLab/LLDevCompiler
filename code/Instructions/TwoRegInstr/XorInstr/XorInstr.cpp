#include "XorInstr.h"

XorInstr::XorInstr(unsigned int line_num) : TwoRegInstr(line_num)
{
}

uint32_t XorInstr::GetOpcode()
{
	return 0x0f;
}