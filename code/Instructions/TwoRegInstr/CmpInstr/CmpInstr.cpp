#include "CmpInstr.h"

CmpInstr::CmpInstr(uint line_num) : TwoRegInstr(line_num)
{
}

uint32_t CmpInstr::GetOpcode()
{
	return 0x0a;
}