#include "PushInstr.h"


PushInstr::PushInstr(unsigned int line_num) : OneRegInstr(line_num)
{
}

uint32_t PushInstr::GetOpcode()
{
	return 0x1c;
}