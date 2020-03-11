#include "AddInstr.h"

AddInstr::AddInstr(token_pos pos) : TwoRegInstr(pos)
{
}

uint32_t AddInstr::GetOpcode()
{
	return 0x01;
}