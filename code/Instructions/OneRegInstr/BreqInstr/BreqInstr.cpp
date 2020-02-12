#include "BreqInstr.h"


BreqInstr::BreqInstr(uint line_num) : OneRegInstr(line_num)
{
}

uint32_t BreqInstr::GetOpcode()
{
	return 0x04;
}