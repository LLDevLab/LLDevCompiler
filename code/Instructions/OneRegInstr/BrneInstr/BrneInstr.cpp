#include "BrneInstr.h"


BrneInstr::BrneInstr(uint line_num) : OneRegInstr(line_num)
{
}

uint32_t BrneInstr::GetOpcode()
{
	return 0x05;
}