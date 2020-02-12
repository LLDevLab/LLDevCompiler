#include "RtrInstr.h"

RtrInstr::RtrInstr(uint line_num) : ShiftRotateInstr(line_num)
{
}

uint32_t RtrInstr::GetOpcode()
{
	return 0x14;
}