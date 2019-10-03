#include "AddcInstr.h"

AddcInstr::AddcInstr(unsigned int line_num) : TwoRegInstr(line_num)
{
}

uint32_t AddcInstr::GetOpcode()
{
	return 0x17;
}