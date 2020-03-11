#include "OneRegImmInstr.h"

OneRegImmInstr::OneRegImmInstr(token_pos pos) : OneRegInstr(pos)
{
	immediate_val = 0;
	immediate_type = DECIMAL;
}

void OneRegImmInstr::SetImmediateValue(string val)
{
	string num_to_convert = val.substr(1, val.size() - 1);
	uint32_t tmp_imm_val = 0;
	string error = "";

	if (IsImmediateHex(val))
		immediate_type = HEXADECIMAL;

	if (!IsImmediateValueCorrect(val))
		ErrorWrongImmediateValue();

	switch (immediate_type)
	{
	case HEXADECIMAL:
		tmp_imm_val = stoi(num_to_convert, NULL, 16);
		break;
	default:
		tmp_imm_val = stoi(num_to_convert);
		break;
	}

	if (IsImmediateNumberCorrect(tmp_imm_val))
		immediate_val = tmp_imm_val;
	else
		ErrorOutOfRangeNumber();
}

uint32_t OneRegImmInstr::GetImmediateValue()
{
	return immediate_val;
}

bool OneRegImmInstr::IsImmediateHex(string val)
{
	if (val.size() < 4)
		return false;

	return tolower(val[2]) == 'x';
}

bool OneRegImmInstr::IsImmediateValueCorrect(string value)
{
	bool ret = false;

	if (value.size() > GetMaxImmStrSize())
		return ret;

	switch (immediate_type)
	{
	case HEXADECIMAL:
		ret = IsHexValueCorrect(value);
		break;
	default:
		ret = IsDecimalValueCorrect(value);
		break;
	}

	return ret;
}

bool OneRegImmInstr::IsImmediateNumberCorrect(int val)
{
	bool ret = false;

	ret = val <= GetMaxImmValue();

	if (ret)
		ret = val >= GetMinImmValue();

	return ret;
}

bool OneRegImmInstr::IsDecimalValueCorrect(string value)
{
	bool ret = true;
	size_t lexeme_size = value.size();

	for (uint i = 1; i < lexeme_size; i++)
	{
		// negative immediate value
		if (i == 1 && value[i] == '-')
		{
			// if there is only minus in lexeme
			if (lexeme_size < 3)
			{
				ret = false;
				break;
			}

			continue;
		}

		ret = IsDigitCorrect(value[i]);
	}

	return ret;
}

bool OneRegImmInstr::IsHexValueCorrect(string value)
{
	bool ret = true;
	size_t lexeme_size = value.size();

	for (uint i = 1; i < lexeme_size; i++)
	{
		// first 2 characters of hex value should be "0x"
		if ((i == 1 && value[i] != '0') || (i == 2 && tolower(value[i]) != 'x'))
		{
			ret = false;
			break;
		}

		if (i == 1 || i == 2)
			continue;

		ret = IsDigitCorrect(value[i]);

		if (!ret)
			break;
	}

	return ret;
}

bool OneRegImmInstr::IsDigitCorrect(char digit)
{
	bool ret = false;
	int max_i;

	switch (immediate_type)
	{
	case HEXADECIMAL:
		max_i = 16;
		break;
	default:
		max_i = 10;
		break;
	}

	for (int i = 0; i < max_i; i++)
	{
		if (tolower(digit) == imm_digits[i])
		{
			ret = true;
			break;
		}
	}

	return ret;
}

void OneRegImmInstr::ErrorWrongImmediateValue()
{
	char buf[100];

	sprintf_s(buf, "Wrong immediate value at line %d.", GetLineNum());
	ShowError(buf);
}

void OneRegImmInstr::ErrorOutOfRangeNumber()
{
	char buf[100];

	sprintf_s(buf, "Immediate number at line %d is out of range (%d - %d).", GetLineNum(), GetMinImmValue(), GetMaxImmValue());
	ShowError(buf);
}

NONTERMINALS OneRegImmInstr::GetInstructionType()
{
	return ONE_REG_IMM_INSTR;
}