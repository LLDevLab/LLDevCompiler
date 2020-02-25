#include "CodeGenerator.h"

// public methods

CodeGenerator::CodeGenerator(string file_name, uint first_line_num):
	obj_file(file_name, first_line_num)
{
	ClearHexs();
}

void CodeGenerator::EndOfFile()
{
	if (this->instruction != NULL)
	{
		SaveLine();
		delete this->instruction;
		this->instruction = NULL;
	}

	hex_line = ":00000001FF";

	hex_file += hex_line;
}

void CodeGenerator::SaveToFile()
{
	obj_file.Open(FILE_IO_OUTPUT);
	obj_file.Write(hex_file);
	obj_file.Close(FILE_IO_OUTPUT);

	ClearHexs();
}

// private methods

string CodeGenerator::ConvertBinsToHex()
{
	uint32_t bins = 0;
	stringstream stream;
	string ret;
	NONTERMINALS instruction_type = instruction->GetInstructionType();

	bins = (GetInstructionOpcode() << 26);

	if (instruction_type != ZERO_REG_INSTR)
	{
		bins |= (GetFirstRegAddr() << 22);

		if(instruction_type == TWO_REG_INSTR)
			bins |= (GetSecondRegAddr() << 18);
		else if (instruction_type == ONE_REG_IMM_INSTR)
			bins |= (GetImmediateValue() << GetImmediateShiftingPos());
	}
	
	// converts integer to hex string
	stream << std::hex << bins;				

	ret = stream.str();

	while (ret.size() < DATA_STR_SIZE)
	{
		ret = "0" + ret;
	}

	return ret;
}

string CodeGenerator::GetCheckSum()
{
	string ret = "";
	uint32_t check_sum = 0;
	uint prev_pos = 1;
	string substr;
	stringstream stream;
	size_t hex_line_size = hex_line.size();

	for (uint i = 1; i < hex_line_size; i++)
	{
		if (i < prev_pos + 2)
			continue;
		
		substr = hex_line.substr(prev_pos, i - prev_pos);

		check_sum += HexStrToInt(substr);

		prev_pos = i;
	}

	if (prev_pos > 1)
	{
		substr = hex_line.substr(prev_pos, hex_line_size - prev_pos);
		check_sum += HexStrToInt(substr);
	}

	check_sum = ~check_sum;
	check_sum += 1;

	stream.clear();

	// converts integer to hex string
	stream << hex << check_sum;
	ret = stream.str();

	return ret.substr(ret.size() - 2, 2);
}

int CodeGenerator::HexStrToInt(string hex_str)
{
	int ret = 0;
	stringstream stream;

	stream.clear();

	// converts hex string to integer
	stream << hex << hex_str;
	stream >> ret;

	return ret;
}

void CodeGenerator::InitHexLine()
{
	hex_line = ":";
	hex_line += HEX_DATA_SIZE;
	hex_line += LineNumToStr(obj_file.GetInitBytecodeLineNum() + instruction->GetLineNum());
}

void CodeGenerator::SaveLine()
{
	hex_line += HEX_DATA_TYPE;
	hex_line += ConvertBinsToHex();
	hex_line += GetCheckSum();

	hex_file += hex_line + "\n";
}

string CodeGenerator::LineNumToStr(uint line_num)
{
	string ret = "";
	const int buf_len = 5;
	char buffer[buf_len];		// 4 digits + \0

	snprintf(buffer, buf_len, "%04x", line_num - 1);	// "%04d" - 4 character integer padded with zeros	

	ret = buffer;

	return ret;
}

void CodeGenerator::ClearHexs()
{
	hex_line = "";
	hex_file = "";
}

void CodeGenerator::SetInstruction(Instruction *instruction)
{
	if (this->instruction != NULL)
	{
		SaveLine();
		delete this->instruction;
	}

	this->instruction = instruction;
}

inline uint32_t CodeGenerator::GetInstructionOpcode()
{
	return instruction->GetOpcode();
}

inline uint32_t CodeGenerator::GetFirstRegAddr()
{
	OneRegInstr *one_reg_instr = (OneRegInstr*)instruction;
	return one_reg_instr->GetFirstRegAddr();
}

inline uint32_t CodeGenerator::GetSecondRegAddr()
{
	TwoRegInstr *two_reg_instr = (TwoRegInstr*)instruction;
	return two_reg_instr->GetSecondRegAddr();
}

inline uint32_t CodeGenerator::GetImmediateValue()
{
	OneRegImmInstr *imm_instr = (OneRegImmInstr*)instruction;
	return imm_instr->GetImmediateValue();
}

inline uint32_t CodeGenerator::GetImmediateShiftingPos()
{
	OneRegImmInstr *imm_instr = (OneRegImmInstr*)instruction;
	return imm_instr->GetShiftingPos();
}