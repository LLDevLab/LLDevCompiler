#include "BrltuInstr.h"


BrltuInstr::BrltuInstr(unsigned int line_num) : OneRegInstr(line_num)
{
}

uint32_t BrltuInstr::GetOpcode()
{
	return 0x08;
}