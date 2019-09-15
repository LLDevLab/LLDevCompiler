#include "BrInstr.h"


BrInstr::BrInstr(unsigned int line_num) : OneRegInstr(line_num)
{
}

uint32_t BrInstr::GetOpcode()
{
	return 0x03;
}