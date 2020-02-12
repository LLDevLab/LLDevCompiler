#include "AndInstr.h"

AndInstr::AndInstr(uint line_num) : TwoRegInstr(line_num)
{
}

uint32_t AndInstr::GetOpcode()
{
	return 0x0e;
}