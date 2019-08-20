#pragma once

#include <string>
#include "../Exceptions/LLDevIOException.h"

using namespace std;

enum TOKENS
{
	UNKNOWN = 0,
	ZERO_REG_OP = 11,
	ONE_REG_OP = 12,
	TWO_REG_OP = 13,
	REGISTER = 14,
	COMMA = 15,
	END_OF_INPUT = 16,
	END_OF_FILE = 17
};

struct token_pos
{
	int line_num;
	int line_pos;
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

