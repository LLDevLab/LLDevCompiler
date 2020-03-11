#include "OrInstr.h"

OrInstr::OrInstr(token_pos pos) : TwoRegInstr(pos)
{
}

uint32_t OrInstr::GetOpcode()
{
	return 0x0d;
}