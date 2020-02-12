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

#include "../SupportComponents/Helpers/Helpers.h"

#define REDUCT_TABLE_ROWS 12
#define REDUCT_TABLE_COLS 4

class Parser
{
public:
	Parser(LexAnalyzer* analyzer, unsigned int first_line_num);
	void Parse();
	unsigned int GetLastBytecodeLine();
private:
	int reduct_table[REDUCT_TABLE_ROWS][REDUCT_TABLE_COLS];
	vector<Token> value_stack;
	vector<int> parse_stack;
	Token input_token;
	LexAnalyzer* analyzer;
	string output;
	CodeGenerator code_generator;
	unsigned int last_bytecode_line;
	unsigned int last_parsed_line;

	void InitReductionTable();
	void Shift();
	void Reduce(int reduct_table_idx);
	void ShowError(token_pos pos, string lexeme, int parse_stack_val, int reduct_table_val);
	void ShowError(token_pos pos, string lexeme);
	Instruction* CreateZeroRegInstr(string lexeme, unsigned int line_num);
	Instruction* CreateOneRegInstr(string lexeme, unsigned int line_num);
	Instruction* CreateTwoRegInstr(string lexeme, unsigned int line_num);
	Instruction* CreateOneRegImmInstr(string lexeme, unsigned int line_num);
	void SetLastBytecodeLine(unsigned int line_num);
};
