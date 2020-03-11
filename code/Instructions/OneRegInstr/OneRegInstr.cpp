#include "OneRegInstr.h"

OneRegInstr::OneRegInstr(token_pos pos) : Instruction(pos)
{
	first_reg_addr = 0;
	max_first_reg_addr = 15;
}

void OneRegInstr::SetFirstReg(string reg)
{
	uint32_t tmp_reg_val = GetRegisterBin(reg);

	if (IsFirstRegAddrCorrect(tmp_reg_val))
		first_reg_addr = tmp_reg_val;
}

uint32_t OneRegInstr::GetFirstRegAddr()
{
	return first_reg_addr;
}

uint32_t OneRegInstr::GetRegisterBin(string lexeme)
{
	uint32_t ret;
	string reg_addr_str = lexeme.substr(1, 2);

	ret = atoi(reg_addr_str.c_str());

	return ret;
}

bool OneRegInstr::IsFirstRegAddrCorrect(uint32_t reg_addr)
{
	return reg_addr <= max_first_reg_addr;
}

void OneRegInstr::SetMaxFirstRegAddr(uint max_addr)
{
	max_first_reg_addr = max_addr;
}

NONTERMINALS OneRegInstr::GetInstructionType()
{
	return ONE_REG_INSTR;
}