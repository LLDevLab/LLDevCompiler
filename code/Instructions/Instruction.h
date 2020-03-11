#pragma once

#include <stdint.h>
#include <string>
#include "../Token/Token.h"
#include "../Exceptions/LLDevIOException/LLDevIOException.h"
#include "../Parser/Nonterminals.h"
#include "../Types/TypeDef.h"

using namespace std;

class Instruction
{
public:
	virtual uint32_t GetOpcode() = 0;
	uint GetBytecodeLineNum();
	uint GetLineNum();
	virtual NONTERMINALS GetInstructionType() = 0;
protected:
	Instruction(token_pos pos);
	void ShowError(string error);
private:
	token_pos pos;
};