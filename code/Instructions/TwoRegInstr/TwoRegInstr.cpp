#include "TwoRegInstr.h"

TwoRegInstr::TwoRegInstr(token_pos pos) : OneRegInstr(pos)
{
	second_reg_addr = 0;
}

void TwoRegInstr::SetSecondReg(string reg)
{
	uint32_t tmp_reg_val = GetRegisterBin(reg);

	if (IsSecondRegAddrCorrect(tmp_reg_val))
		second_reg_addr = tmp_reg_val;
}

uint32_t TwoRegInstr::GetSecondRegAddr()
{
	return second_reg_addr;
}

bool TwoRegInstr::IsSecondRegAddrCorrect(uint32_t reg_addr)
{
	return reg_addr <= max_second_reg_addr;
}

void TwoRegInstr::SetMaxSecondRegAddr(uint max_addr)
{
	max_second_reg_addr = max_addr;
}

NONTERMINALS TwoRegInstr::GetInstructionType()
{
	return TWO_REG_INSTR;
}