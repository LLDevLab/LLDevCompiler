#include "BrltuInstr.h"


BrltuInstr::BrltuInstr(token_pos pos) : OneRegInstr(pos)
{
}

uint32_t BrltuInstr::GetOpcode()
{
	return 0x08;
}