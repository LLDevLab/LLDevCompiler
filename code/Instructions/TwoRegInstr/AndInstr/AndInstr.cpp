#include "AndInstr.h"

AndInstr::AndInstr(unsigned int line_num) : TwoRegInstr(line_num)
{
}

uint32_t AndInstr::GetOpcode()
{
	return 0x0e;
}