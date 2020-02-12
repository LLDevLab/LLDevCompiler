#include "AddInstr.h"

AddInstr::AddInstr(uint line_num) : TwoRegInstr(line_num)
{
}

uint32_t AddInstr::GetOpcode()
{
	return 0x01;
}