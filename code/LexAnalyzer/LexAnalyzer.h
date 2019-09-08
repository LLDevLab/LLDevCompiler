#pragma once

#include <iostream>
#include <fstream>
#include <vector>
#include <exception>
#include <string>
#include "../Token/Token.h"

using namespace std;

class LexAnalyzer
{
public:
	LexAnalyzer(const char* file);
	~LexAnalyzer();

	Token GetNextToken();
	const char* GetFileName();
private:
	const char* token_delim = " ";

	const char* file_name;
	ifstream ios_file;

	vector<string> lexemes;
	vector<int> lex_positions;
	unsigned int cur_token_index;
	int cur_line;
	int cur_pos;

	string ReadLine();
	void GetLexemes(string line);
	TOKENS GetTokenFromLexeme(string lexeme);
	bool IsTwoRegOp(string lexeme);
	bool IsRegister(string lexeme);
	bool IsOneRegOp(string lexeme);
	bool IsZeroRegOp(string lexeme);
	bool IsOneRegImmOp(string lexete);
	bool IsImmediate(string lexeme);
	bool IsImmHex(string lexeme);
	void AddLexeme(string lexeme, int pos);
	IMMEDIATE_TYPE GetImmediateType(string lexeme);
};