#include "RtlInstr.h"

RtlInstr::RtlInstr(token_pos pos) : ShiftRotateInstr(pos)
{
}

uint32_t RtlInstr::GetOpcode()
{
	return 0x13;
}