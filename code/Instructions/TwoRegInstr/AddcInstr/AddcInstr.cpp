#include "AddcInstr.h"

AddcInstr::AddcInstr(token_pos pos) : TwoRegInstr(pos)
{
}

uint32_t AddcInstr::GetOpcode()
{
	return 0x17;
}