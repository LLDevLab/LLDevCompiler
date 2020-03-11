#include "BrgtuInstr.h"


BrgtuInstr::BrgtuInstr(token_pos pos) : OneRegInstr(pos)
{
}

uint32_t BrgtuInstr::GetOpcode()
{
	return 0x09;
}