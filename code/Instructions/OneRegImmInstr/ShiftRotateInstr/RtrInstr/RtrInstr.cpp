#include "RtrInstr.h"

RtrInstr::RtrInstr(token_pos pos) : ShiftRotateInstr(pos)
{
}

uint32_t RtrInstr::GetOpcode()
{
	return 0x14;
}