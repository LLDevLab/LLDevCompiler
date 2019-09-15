#include "LdiInstr.h"

// 4 194 303 is a max 22 bit value
#define MAX_IMM_VAL 4194303

// -2097152 is a min 22 bit value
#define MIN_IMM_VAL -2097152

#define MAX_STR_SIZE 10
#define SHIFTING_POS 0

LdiInstr::LdiInstr(unsigned int line_num) : OneRegImmInstr(line_num)
{
}

uint32_t LdiInstr::GetOpcode()
{
	return 0x0c;
}

uint32_t LdiInstr::GetShiftingPos()
{
	return SHIFTING_POS;
}

int LdiInstr::GetMaxImmValue()
{
	return MAX_IMM_VAL;
}

int LdiInstr::GetMinImmValue()
{
	return MIN_IMM_VAL;
}

unsigned int LdiInstr::GetMaxImmStrSize()
{
	return MAX_STR_SIZE;
}