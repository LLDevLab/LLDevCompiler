#pragma once

#include <iostream>
#include <fstream>
#include <vector>
#include <exception>
#include <string>
#include <map>
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
	unsigned int cur_token_index;
	int cur_line;
	int cur_bytecode_line;
	map<string, int> label_to_line_num_map;

	string ReadLine();
	void GetLexemes(string line);
	TOKENS GetTokenFromLexeme(string lexeme);
	bool IsTwoRegOp(string lexeme);
	bool IsRegister(string lexeme);
	bool IsOneRegOp(string lexeme);
	bool IsZeroRegOp(string lexeme);
	bool IsOneRegImmOp(string lexete);
	bool IsImmediate(string lexeme);
	bool IsComment(string str_line);
	bool IsEmptyLine(string str_line);
	bool IsLabel(string str_line, bool isDefinition);
	void SetTokenLexeme(Token* token, string lexeme);
	string GetNextValidLine(string str_line);
	void AddLexeme(string lexeme, int pos);
};