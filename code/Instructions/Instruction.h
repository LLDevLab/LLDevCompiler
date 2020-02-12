#pragma once

#include <stdint.h>
#include <string>
#include "../Exceptions/LLDevIOException/LLDevIOException.h"
#include "../Parser/Nonterminals.h"
#include "../Types/TypeDef.h"

using namespace std;

class Instruction
{
public:
	virtual uint32_t GetOpcode() = 0;
	uint GetLineNum();
	virtual NONTERMINALS GetInstructionType() = 0;
protected:
	Instruction(uint line_num);
	void ShowError(string error);
private:
	uint line_num;
};