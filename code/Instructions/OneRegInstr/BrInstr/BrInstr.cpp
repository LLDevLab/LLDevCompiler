#include "BrInstr.h"


BrInstr::BrInstr(uint line_num) : OneRegInstr(line_num)
{
}

uint32_t BrInstr::GetOpcode()
{
	return 0x03;
}