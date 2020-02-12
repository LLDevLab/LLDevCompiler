#include "NoopInstr.h"

NoopInstr::NoopInstr(uint line_num) : ZeroRegInstr(line_num)
{
}

uint32_t NoopInstr::GetOpcode()
{
	return 0x00;
}