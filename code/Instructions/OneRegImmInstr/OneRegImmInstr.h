#pragma once

#include "../OneRegInstr/OneRegInstr.h"
#include <string>

using namespace std;

class OneRegImmInstr: public OneRegInstr
{
public:
	virtual uint32_t GetOpcode() = 0;
	uint32_t GetImmediateValue();
	void SetImmediateValue(string val);
	virtual uint32_t GetShiftingPos() = 0;
	NONTERMINALS GetInstructionType();
protected:
	enum IMMEDIATE_TYPE
	{
		DECIMAL,
		HEXADECIMAL
	};

	OneRegImmInstr(unsigned int line_num);
	bool IsImmediateHex(string val);
	virtual bool IsImmediateValueCorrect(string value);
	bool IsImmediateNumberCorrect(int val);
	bool IsDecimalValueCorrect(string value);
	bool IsHexValueCorrect(string value);
	bool IsDigitCorrect(char digit);
	virtual int GetMaxImmValue() = 0;
	virtual int GetMinImmValue() = 0;
	virtual unsigned int GetMaxImmStrSize() = 0;
private:
	int immediate_val;
	IMMEDIATE_TYPE immediate_type;

	char imm_digits[16] = { '0', '1', '2', '3', '4', '5', '6', '7', '8', '9', 'a', 'b', 'c', 'd', 'e', 'f' };

	void ErrorWrongImmediateValue();
	void ErrorOutOfRangeNumber();
};