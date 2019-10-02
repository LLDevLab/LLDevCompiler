#include "RtlcInstr.h"

RtlcInstr::RtlcInstr(unsigned int line_num) : ShiftRotateInstr(line_num)
{
}

uint32_t RtlcInstr::GetOpcode()
{
	return 0x15;
}