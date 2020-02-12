#pragma once 

#include "../Instruction.h"

using namespace std;

class ZeroRegInstr: public Instruction
{
public:
	virtual uint32_t GetOpcode() = 0;
	NONTERMINALS GetInstructionType();
protected:
	ZeroRegInstr(uint line_num);
};