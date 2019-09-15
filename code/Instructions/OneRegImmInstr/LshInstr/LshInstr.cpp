#include "LshInstr.h"

// 31 is a max 5 bit value
#define MAX_IMM_VAL 31
#define MIN_IMM_VAL 0

#define MAX_STR_SIZE 5
#define SHIFTING_POS 17

LshInstr::LshInstr(unsigned int line_num) : OneRegImmInstr(line_num)
{
}

uint32_t LshInstr::GetOpcode()
{
	return 0x11;
}

uint32_t LshInstr::GetShiftingPos()
{
	return SHIFTING_POS;
}

int LshInstr::GetMaxImmValue()
{
	return MAX_IMM_VAL;
}

int LshInstr::GetMinImmValue()
{
	return MIN_IMM_VAL;
}

unsigned int LshInstr::GetMaxImmStrSize()
{
	return MAX_STR_SIZE;
}