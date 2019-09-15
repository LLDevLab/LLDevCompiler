#include "ZeroRegInstr.h"

ZeroRegInstr::ZeroRegInstr(unsigned int line_num) : Instruction(line_num)
{
}

NONTERMINALS ZeroRegInstr::GetInstructionType()
{
	return ZERO_REG_INSTR;
}