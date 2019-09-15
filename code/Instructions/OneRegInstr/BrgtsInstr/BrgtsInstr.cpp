#include "BrgtsInstr.h"


BrgtsInstr::BrgtsInstr(unsigned int line_num) : OneRegInstr(line_num)
{
}

uint32_t BrgtsInstr::GetOpcode()
{
	return 0x07;
}