#include "RshInstr.h"

RshInstr::RshInstr(uint line_num) : ShiftRotateInstr(line_num)
{
}

uint32_t RshInstr::GetOpcode()
{
	return 0x12;
}