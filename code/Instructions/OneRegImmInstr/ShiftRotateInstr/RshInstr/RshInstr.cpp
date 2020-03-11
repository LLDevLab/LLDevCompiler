#include "RshInstr.h"

RshInstr::RshInstr(token_pos pos) : ShiftRotateInstr(pos)
{
}

uint32_t RshInstr::GetOpcode()
{
	return 0x12;
}