#pragma once

#include <vector>
#include "../LexAnalyzer/LexAnalyzer.h"
#include "../CodeGenerator/CodeGenerator.h"

#define REDUCT_NONE -1
#define REDUCT_ERROR -2
#define REDUCT_TABLE_ROWS 10
#define REDUCT_TABLE_COLS 4

#define STACK_ERROR "Stack out of range."

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

	void InitReductionTable();
	void Shift();
	void Reduce(int reduct_table_idx);
	string LineNumToStr(int line_num);
	void ShowError(token_pos pos, string lexeme);
	void ShowError(token_pos pos, string lexeme, int parse_stack_val, int reduct_table_val);
};

