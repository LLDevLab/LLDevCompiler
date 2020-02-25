#pragma once

#include <iostream>
#include <fstream>
#include <vector>
#include <exception>
#include <string>
#include "../Token/Token.h"
#include "../SupportComponents/Helpers/Helpers.h"
#include "../SupportComponents/SymbolTable/SymbolTable.h"
#include "../Types/TypeDef.h"
#include "../SupportComponents/Helpers/Helpers.h"

using namespace std;

class LexAnalyzer
{
public:
	LexAnalyzer(string file, SymbolTable* symbol_table);
	~LexAnalyzer();

	Token GetNextToken();
	string GetFileName();
private:
	const char* token_delim = " ";
	string file_name;

	ifstream ios_file;
	vector<string> lexemes;
	uint cur_token_index;
	int cur_line;
	int cur_bytecode_line;
	SymbolTable* symbol_table;

	string ReadLine();
	void GetLexemes(string line);
	TOKENS GetTokenFromLexeme(string lexeme);
	bool IsTwoRegOp(string lexeme);
	bool IsRegister(string lexeme);
	bool IsOneRegOp(string lexeme);
	bool IsZeroRegOp(string lexeme);
	bool IsOneRegImmOp(string lexete);
	bool IsImmediate(string lexeme);
	void SetTokenLexeme(Token* token, string lexeme);
	string GetNextValidLine(string str_line);
	void AddLexeme(string lexeme, int pos);
	void OpenFile();
};