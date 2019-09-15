#include "CmpInstr.h"

CmpInstr::CmpInstr(unsigned int line_num) : TwoRegInstr(line_num)
{
}

uint32_t CmpInstr::GetOpcode()
{
	return 0x0a;
}