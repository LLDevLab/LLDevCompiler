#include "RtlInstr.h"

RtlInstr::RtlInstr(unsigned int line_num) : ShiftRotateInstr(line_num)
{
}

uint32_t RtlInstr::GetOpcode()
{
	return 0x13;
}