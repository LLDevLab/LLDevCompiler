#include "RetInstr.h"

RetInstr::RetInstr(unsigned int line_num) : ZeroRegInstr(line_num)
{
}

uint32_t RetInstr::GetOpcode()
{
	return 0x1f;
}