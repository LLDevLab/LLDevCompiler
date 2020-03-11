#include "RtlcInstr.h"

RtlcInstr::RtlcInstr(token_pos pos) : ShiftRotateInstr(pos)
{
}

uint32_t RtlcInstr::GetOpcode()
{
	return 0x15;
}