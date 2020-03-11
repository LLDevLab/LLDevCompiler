#include "NotInstr.h"


NotInstr::NotInstr(token_pos pos) : OneRegInstr(pos)
{
}

uint32_t NotInstr::GetOpcode()
{
	return 0x10;
}