#include "NoopInstr.h"

NoopInstr::NoopInstr(unsigned int line_num) : ZeroRegInstr(line_num)
{
}

uint32_t NoopInstr::GetOpcode()
{
	return 0x00;
}