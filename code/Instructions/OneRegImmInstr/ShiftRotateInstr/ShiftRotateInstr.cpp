#include "ShiftRotateInstr.h"

// 31 is a max 5 bit value
#define MAX_IMM_VAL 31
#define MIN_IMM_VAL 0

#define MAX_STR_SIZE 5
#define SHIFTING_POS 17

ShiftRotateInstr::ShiftRotateInstr(token_pos pos) : OneRegImmInstr(pos)
{
}

uint32_t ShiftRotateInstr::GetShiftingPos()
{
	return SHIFTING_POS;
}

int ShiftRotateInstr::GetMaxImmValue()
{
	return MAX_IMM_VAL;
}

int ShiftRotateInstr::GetMinImmValue()
{
	return MIN_IMM_VAL;
}

uint ShiftRotateInstr::GetMaxImmStrSize()
{
	return MAX_STR_SIZE;
}