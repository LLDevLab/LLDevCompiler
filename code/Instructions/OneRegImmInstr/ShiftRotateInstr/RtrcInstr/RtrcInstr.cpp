#include "RtrcInstr.h"

RtrcInstr::RtrcInstr(uint line_num) : ShiftRotateInstr(line_num)
{
}

uint32_t RtrcInstr::GetOpcode()
{
	return 0x16;
}