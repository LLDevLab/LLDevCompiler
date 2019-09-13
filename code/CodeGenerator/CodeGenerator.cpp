#include "CodeGenerator.h"

// public methods

CodeGenerator::CodeGenerator()
{
	ClearHexs();
	ClearBinaries();

	InitHexLine();
}

void CodeGenerator::EndOfFile()
{
	hex_line = ":00000001FF";

	hex_file += hex_line;
}

void CodeGenerator::SetLineNum(int line_num)
{
	hex_line += LineNumToStr(line_num);
}

void CodeGenerator::SetOpcodeToken(Token token)
{
	opcode_bin = GetOpcodeBin(token.GetLexeme());
}

void CodeGenerator::SetFirstRegisterToken(Token token)
{
	reg1_bin = GetRegisterBin(token.GetLexeme());
	is_reg1_set = true;
}

void CodeGenerator::SetSecondRegisterToken(Token token)
{
	reg2_bin = GetRegisterBin(token.GetLexeme());
	is_reg2_set = true;
}

void CodeGenerator::SaveToFile(const char* file)
{
	ofstream file_stream;
	string hex_file_name = RemoveFileExtension(file);

	hex_file_name += OUTPUT_FILE_EXT;

	file_stream.open(hex_file_name);

	file_stream << hex_file;

	file_stream.close();

	ClearHexs();
}

// private methods

string CodeGenerator::RemoveFileExtension(const char* file_name)
{
	string ret = file_name;
	size_t found_pos = ret.find_last_of(".");

	if (found_pos == string::npos)
		return file_name;
	
	ret = ret.substr(0, found_pos);

	return ret;
}

string CodeGenerator::ConvertBinsToHex()
{
	uint32_t bins = 0;
	stringstream stream;
	string ret;

	// if opcode not equal noop
	if (opcode_bin != 0)
		bins = (opcode_bin << 26);
		
	if(is_reg1_set)
		bins |= (reg1_bin << 22);

	if (is_reg2_set)
		bins |= (reg2_bin << 18);

	if(is_imm_set)
		bins |= imm_bin;

	// converts integer to hex string
	stream << std::hex << bins;				

	ret = stream.str();

	while (ret.size() < DATA_STR_SIZE)
	{
		ret = "0" + ret;
	}

	return ret;
}

uint32_t CodeGenerator::GetRegisterBin(string lexeme)
{
	uint32_t ret;
	string reg_addr_str = lexeme.substr(1, 2);

	ret = atoi(reg_addr_str.c_str());

	return ret;
}

void CodeGenerator::ClearBinaries()
{
	opcode_bin = 0;
	reg1_bin = REG_ADDR_MAX + 1;
	reg2_bin = REG_ADDR_MAX + 1;

	is_reg1_set = false;
	is_reg2_set = false; 
	is_imm_set = false;
}

uint32_t CodeGenerator::GetOpcodeBin(string lexeme)
{
	uint32_t ret = 0;

	if (lexeme == "add")
		ret = 0x01;
	else if (lexeme == "sub")
		ret = 0x02;
	else if (lexeme == "br")
		ret = 0x03;
	else if (lexeme == "breq")
		ret = 0x04;
	else if (lexeme == "brne")
		ret = 0x05;
	else if (lexeme == "brlts")
		ret = 0x06;
	else if (lexeme == "brgts")
		ret = 0x07;
	else if (lexeme == "brltu")
		ret = 0x08;
	else if (lexeme == "brgtu")
		ret = 0x09;
	else if (lexeme == "cmp")
		ret = 0x0a;
	else if (lexeme == "clr")
		ret = 0x0b;
	else if (lexeme == "ldi")
		ret = 0x0c;
	else if (lexeme == "or")
		ret = 0x0d;
	else if (lexeme == "and")
		ret = 0x0e;
	else if (lexeme == "xor")
		ret = 0x0f;
	else if (lexeme == "noop")
		ret = 0x00;

	return ret;
}

string CodeGenerator::GetCheckSum()
{
	string ret = "";
	uint32_t check_sum = 0;
	unsigned int prev_pos = 1;
	string substr;
	stringstream stream;
	size_t hex_line_size = hex_line.size();

	for (unsigned int i = 1; i < hex_line_size; i++)
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
	if (hex_line != "")
	{
		SaveLine();
		ClearBinaries();
	}

	hex_line = ":";
	hex_line += HEX_DATA_SIZE;
}

void CodeGenerator::SaveLine()
{
	hex_line += HEX_DATA_TYPE;
	hex_line += ConvertBinsToHex();
	hex_line += GetCheckSum();

	hex_file += hex_line + "\n";
}

string CodeGenerator::LineNumToStr(int line_num)
{
	string ret = "";	
	char buffer[5];		// 4 digits + \0
	int zeroes_cnt = 0;

	snprintf(buffer, 5, "%04d", line_num - 1);	// "%04d" - 4 character integer padded with zeros	

	ret = buffer;

	return ret;
}

void CodeGenerator::ClearHexs()
{
	hex_line = "";
	hex_file = "";
}

void CodeGenerator::SetImmediateToken(Token token)
{
	string lexeme = token.GetLexeme();
	string num_to_convert = lexeme.substr(1, lexeme.size() - 1);

	is_imm_set = true;

	switch (token.GetImmediateType())
	{
	case HEXADECIMAL:
		imm_bin = stoi(num_to_convert, NULL, 16);
		break;
	default:
		imm_bin = stoi(num_to_convert);
		break;
	}
}