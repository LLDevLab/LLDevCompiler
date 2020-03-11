#include "CallInstr.h"


CallInstr::CallInstr(token_pos pos) : OneRegInstr(pos)
{
}

uint32_t CallInstr::GetOpcode()
{
	return 0x1e;
}