#pragma once

#include <vector>
#include <ctype.h>
#include "../LexAnalyzer/LexAnalyzer.h"
#include "../CodeGenerator/CodeGenerator.h"

#define REDUCT_TABLE_ROWS 12
#define REDUCT_TABLE_COLS 4

class Parser
{
public:
	Parser(LexAnalyzer* analyzer);
	void Parse();
private:
	int reduct_table[REDUCT_TABLE_ROWS][REDUCT_TABLE_COLS];
	vector<Token> value_stack;
	vector<int> parse_stack;
	Token input_token;
	LexAnalyzer* analyzer;
	string output;
	CodeGenerator code_generator;
	char imm_digits[16] = {'0', '1', '2', '3', '4', '5', '6', '7', '8', '9', 'a', 'b', 'c', 'd', 'e', 'f'};

	void InitReductionTable();
	void Shift();
	void Reduce(int reduct_table_idx);
	string LineNumToStr(int line_num);
	void ShowError(token_pos pos, string lexeme);
	void ShowError(token_pos pos, string lexeme, int parse_stack_val, int reduct_table_val);
	void ShowToLongNumberError(token_pos pos, string lexeme);
	bool IsImmediateCorrect(string lexeme, IMMEDIATE_TYPE type);
	bool IsImmDecimalCorrect(string lexeme);
	bool IsImmHexCorrect(string lexeme);
	bool IsCorrectNumber(char num, IMMEDIATE_TYPE type);
	bool IsCorrectNumberSize(string lexeme, IMMEDIATE_TYPE type);
};

