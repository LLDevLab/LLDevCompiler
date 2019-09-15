#pragma once

#include <stdint.h>
#include <string>
#include "../Exceptions/LLDevIOException.h"
#include "../Parser/Nonterminals.h"
/**/

using namespace std;

class Instruction
{
public:
	virtual uint32_t GetOpcode() = 0;
	unsigned int GetLineNum();
	virtual NONTERMINALS GetInstructionType() = 0;
protected:
	Instruction(unsigned int line_num);
	void ShowError(string error);
private:
	unsigned int line_num;
};