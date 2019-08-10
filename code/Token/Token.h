#pragma once

#include <string>
#include "../Exceptions/LLDevIOException.h"

using namespace std;

enum TOKENS
{
	UNKNOWN = 0,
	ONE_REG_OP = 11,
	TWO_REG_OP = 12,
	REGISTER = 13,
	COMMA = 14,
	END_OF_INPUT = 15,
	END_OF_FILE = 16
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

