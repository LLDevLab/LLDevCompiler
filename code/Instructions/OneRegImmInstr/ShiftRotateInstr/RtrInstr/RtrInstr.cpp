#include "RtrInstr.h"

RtrInstr::RtrInstr(unsigned int line_num) : ShiftRotateInstr(line_num)
{
}

uint32_t RtrInstr::GetOpcode()
{
	return 0x14;
}