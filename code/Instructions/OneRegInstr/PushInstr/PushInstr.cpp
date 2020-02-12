#include "PushInstr.h"


PushInstr::PushInstr(uint line_num) : OneRegInstr(line_num)
{
}

uint32_t PushInstr::GetOpcode()
{
	return 0x1c;
}