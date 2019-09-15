#include "NotInstr.h"


NotInstr::NotInstr(unsigned int line_num) : OneRegInstr(line_num)
{
}

uint32_t NotInstr::GetOpcode()
{
	return 0x10;
}