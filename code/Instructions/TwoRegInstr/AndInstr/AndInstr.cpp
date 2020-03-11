#include "AndInstr.h"

AndInstr::AndInstr(token_pos pos) : TwoRegInstr(pos)
{
}

uint32_t AndInstr::GetOpcode()
{
	return 0x0e;
}