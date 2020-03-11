#include "ClrInstr.h"


ClrInstr::ClrInstr(token_pos pos) : OneRegInstr(pos)
{
}

uint32_t ClrInstr::GetOpcode()
{
	return 0x0b;
}