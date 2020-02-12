#include "BrgtuInstr.h"


BrgtuInstr::BrgtuInstr(uint line_num) : OneRegInstr(line_num)
{
}

uint32_t BrgtuInstr::GetOpcode()
{
	return 0x09;
}