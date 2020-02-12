#include "NotInstr.h"


NotInstr::NotInstr(uint line_num) : OneRegInstr(line_num)
{
}

uint32_t NotInstr::GetOpcode()
{
	return 0x10;
}