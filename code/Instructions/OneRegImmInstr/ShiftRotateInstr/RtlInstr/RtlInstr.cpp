#include "RtlInstr.h"

RtlInstr::RtlInstr(uint line_num) : ShiftRotateInstr(line_num)
{
}

uint32_t RtlInstr::GetOpcode()
{
	return 0x13;
}