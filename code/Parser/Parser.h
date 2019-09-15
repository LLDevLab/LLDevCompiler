#pragma once

#include <vector>
#include <ctype.h>
#include "../LexAnalyzer/LexAnalyzer.h"
#include "../CodeGenerator/CodeGenerator.h"
#include "Nonterminals.h"
#include "../Instructions/ZeroRegInstr/NoopInstr/NoopInstr.h"
#include "../Instructions/OneRegInstr/BrInstr/BrInstr.h"
#include "../Instructions/OneRegInstr/BreqInstr/BreqInstr.h"
#include "../Instructions/OneRegInstr/BrneInstr/BrneInstr.h"
#include "../Instructions/OneRegInstr/BrltsInstr/BrltsInstr.h"
#include "../Instructions/OneRegInstr/BrgtsInstr/BrgtsInstr.h"
#include "../Instructions/OneRegInstr/BrltuInstr/BrltuInstr.h"
#include "../Instructions/OneRegInstr/BrgtuInstr/BrgtuInstr.h"
#include "../Instructions/OneRegInstr/ClrInstr/ClrInstr.h"
#include "../Instructions/OneRegInstr/NotInstr/NotInstr.h"
#include "../Instructions/OneRegInstr/NotInstr/NotInstr.h"
#include "../Instructions/TwoRegInstr/AddInstr/AddInstr.h"
#include "../Instructions/TwoRegInstr/SubInstr/SubInstr.h"
#include "../Instructions/TwoRegInstr/CmpInstr/CmpInstr.h"
#include "../Instructions/TwoRegInstr/OrInstr/OrInstr.h"
#include "../Instructions/TwoRegInstr/AndInstr/AndInstr.h"
#include "../Instructions/TwoRegInstr/XorInstr/XorInstr.h"
#include "../Instructions/OneRegImmInstr/LdiInstr/LdiInstr.h"

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
