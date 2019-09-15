#include "LshInstr.h"

LshInstr::LshInstr(unsigned int line_num) : ShiftRotateInstr(line_num)
{
}

uint32_t LshInstr::GetOpcode()
{
	return 0x11;
}