#include "NoopInstr.h"

NoopInstr::NoopInstr(token_pos pos) : ZeroRegInstr(pos)
{
}

uint32_t NoopInstr::GetOpcode()
{
	return 0x00;
}