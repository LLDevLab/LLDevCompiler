#include "CallInstr.h"


CallInstr::CallInstr(uint line_num) : OneRegInstr(line_num)
{
}

uint32_t CallInstr::GetOpcode()
{
	return 0x1e;
}