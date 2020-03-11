#include "RetInstr.h"

RetInstr::RetInstr(token_pos pos) : ZeroRegInstr(pos)
{
}

uint32_t RetInstr::GetOpcode()
{
	return 0x1f;
}