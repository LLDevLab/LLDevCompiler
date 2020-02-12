#include "OrInstr.h"

OrInstr::OrInstr(uint line_num) : TwoRegInstr(line_num)
{
}

uint32_t OrInstr::GetOpcode()
{
	return 0x0d;
}