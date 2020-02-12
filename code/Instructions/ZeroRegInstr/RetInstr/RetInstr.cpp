#include "RetInstr.h"

RetInstr::RetInstr(uint line_num) : ZeroRegInstr(line_num)
{
}

uint32_t RetInstr::GetOpcode()
{
	return 0x1f;
}