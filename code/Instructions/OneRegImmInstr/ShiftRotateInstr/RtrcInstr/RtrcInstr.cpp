#include "RtrcInstr.h"

RtrcInstr::RtrcInstr(token_pos pos) : ShiftRotateInstr(pos)
{
}

uint32_t RtrcInstr::GetOpcode()
{
	return 0x16;
}