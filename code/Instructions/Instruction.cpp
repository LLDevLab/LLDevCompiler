#include "Instruction.h"

Instruction::Instruction(token_pos pos)
{
	this->pos = pos;
}

uint Instruction::GetBytecodeLineNum()
{
	return pos.bytecode_line_num;
}

uint Instruction::GetLineNum()
{
	return pos.line_num;
}

void Instruction::ShowError(string error)
{
	throw LLDevIOException(error);
}