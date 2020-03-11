#include "ZeroRegInstr.h"

ZeroRegInstr::ZeroRegInstr(token_pos pos) : Instruction(pos)
{
}

NONTERMINALS ZeroRegInstr::GetInstructionType()
{
	return ZERO_REG_INSTR;
}