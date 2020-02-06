#pragma once

#include <string>
#include "../Exceptions/LLDevIOException/LLDevIOException.h"

using namespace std;

enum TOKENS
{
	UNKNOWN = 100,
	ZERO_REG_OP = 101,
	ONE_REG_OP = 102,
	ONE_REG_IMM_OP = 103,
	TWO_REG_OP = 104,
	REGISTER = 105,
	COMMA = 106,
	IMMEDIATE = 107,
	END_OF_INPUT = 108,
	END_OF_FILE = 109
};

struct token_pos
{
	int line_num;
	int bytecode_line_num;
};

class Token
{
public:
	Token();
	
	void SetTokenValue(TOKENS value);
	void SetTokenPos(token_pos pos);
	void SetLexeme(string lexeme);

	TOKENS GetTokenValue();
	token_pos GetPosition();
	string GetLexeme();

private:
	TOKENS token;
	token_pos pos;
	string lexeme;
};

