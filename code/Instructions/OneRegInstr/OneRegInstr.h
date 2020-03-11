#pragma once

#include <string>
#include "../Instruction.h"

using namespace std;

class OneRegInstr: public Instruction
{
public:
	virtual uint32_t GetOpcode() = 0;
	uint32_t GetFirstRegAddr();
	void SetFirstReg(string reg);
	NONTERMINALS GetInstructionType();
protected:
	OneRegInstr(token_pos pos);
	uint32_t GetRegisterBin(string lexeme);
	virtual bool IsFirstRegAddrCorrect(uint32_t reg_addr);
	void SetMaxFirstRegAddr(uint max_addr);
private:
	uint32_t first_reg_addr;
	uint max_first_reg_addr;
};