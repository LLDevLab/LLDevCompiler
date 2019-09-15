#include "BrltsInstr.h"


BrltsInstr::BrltsInstr(unsigned int line_num) : OneRegInstr(line_num)
{
}

uint32_t BrltsInstr::GetOpcode()
{
	return 0x06;
}