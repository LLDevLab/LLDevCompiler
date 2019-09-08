#include "Token.h"

Token::Token()
{
	token = UNKNOWN;
	this->pos = {
		0,
		0
	};

	lexeme = "";
	imm_type = DECIMAL;
}

TOKENS Token::GetTokenValue()
{
	return token;
}

token_pos Token::GetPosition()
{
	return pos;
}

string Token::GetLexeme()
{
	return lexeme;
}

void Token::SetLexeme(string lexeme)
{
	this->lexeme = lexeme;
}

void Token::SetTokenPos(token_pos pos)
{
	this->pos = pos;
}

void Token::SetTokenValue(TOKENS value)
{
	token = value;
}

void Token::SetImmediateType(IMMEDIATE_TYPE type)
{
	imm_type = type;
}

IMMEDIATE_TYPE Token::GetImmediateType()
{
	return imm_type;
}