#include "Instruction.h"

Instruction::Instruction(uint line_num)
{
	this->line_num = line_num;
}

uint Instruction::GetLineNum()
{
	return line_num;
}

void Instruction::ShowError(string error)
{
	throw LLDevIOException(error);
}