#pragma once

#include <vector>
#include <ctype.h>
#include "../LexAnalyzer/LexAnalyzer.h"
#include "../CodeGenerator/CodeGenerator.h"
#include "Nonterminals.h"

#include "../Instructions/ZeroRegInstr/ZeroRegInstructions.h"
#include "../Instructions/OneRegInstr/OneRegInstructions.h"
#include "../Instructions/TwoRegInstr/TwoRegInstructions.h"
#include "../Instructions/OneRegImmInstr/OneRegImmInstuctions.h"

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

	void InitReductionTable();
	void Shift();
	void Reduce(int reduct_table_idx);
	void ShowError(token_pos pos, string lexeme, int parse_stack_val, int reduct_table_val);
	void ShowError(token_pos pos, string lexeme);
	Instruction* CreateZeroRegInstr(string lexeme, unsigned int line_num);
	Instruction* CreateOneRegInstr(string lexeme, unsigned int line_num);
	Instruction* CreateTwoRegInstr(string lexeme, unsigned int line_num);
	Instruction* CreateOneRegImmInstr(string lexeme, unsigned int line_num);
};
