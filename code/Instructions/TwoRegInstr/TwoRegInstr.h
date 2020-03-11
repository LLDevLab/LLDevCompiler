#pragma once

#include "../OneRegInstr/OneRegInstr.h"

using namespace std;

class TwoRegInstr: public OneRegInstr
{
public:
	virtual uint32_t GetOpcode() = 0;
	uint32_t GetSecondRegAddr();
	void SetSecondReg(string reg);
protected:
	TwoRegInstr(token_pos pos);
	virtual bool IsSecondRegAddrCorrect(uint32_t reg_addr);
	void SetMaxSecondRegAddr(uint max_addr);
	NONTERMINALS GetInstructionType();
private:
	uint32_t second_reg_addr;
	uint max_second_reg_addr;
};