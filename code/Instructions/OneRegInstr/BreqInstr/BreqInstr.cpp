#include "BreqInstr.h"


BreqInstr::BreqInstr(unsigned int line_num) : OneRegInstr(line_num)
{
}

uint32_t BreqInstr::GetOpcode()
{
	return 0x04;
}