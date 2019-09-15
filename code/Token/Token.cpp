#include "Token.h"

Token::Token()
{
	token = UNKNOWN;
	this->pos = {
		0,
		0
	};

	lexeme = "";
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