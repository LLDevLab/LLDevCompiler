#include "LshInstr.h"

LshInstr::LshInstr(token_pos pos) : ShiftRotateInstr(pos)
{
}

uint32_t LshInstr::GetOpcode()
{
	return 0x11;
}