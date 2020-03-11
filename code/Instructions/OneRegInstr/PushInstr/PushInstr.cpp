#include "PushInstr.h"


PushInstr::PushInstr(token_pos pos) : OneRegInstr(pos)
{
}

uint32_t PushInstr::GetOpcode()
{
	return 0x1c;
}