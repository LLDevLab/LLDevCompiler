#include "Instruction.h"

Instruction::Instruction(unsigned int line_num)
{
	this->line_num = line_num;
}

unsigned int Instruction::GetLineNum()
{
	return line_num;
}

void Instruction::ShowError(string error)
{
	throw LLDevIOException(error);
}