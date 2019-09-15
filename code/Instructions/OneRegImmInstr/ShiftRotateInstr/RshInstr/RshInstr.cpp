#include "RshInstr.h"

RshInstr::RshInstr(unsigned int line_num) : ShiftRotateInstr(line_num)
{
}

uint32_t RshInstr::GetOpcode()
{
	return 0x12;
}