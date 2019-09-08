#include "Parser.h"

#define REDUCT_NONE -1
#define REDUCT_ERROR -2
#define STACK_ERROR "Stack out of range."

// 4194303 is a max 22 bit value
#define MAX_IMM_VALUE 4194303

// Nonterminal values could be from 0 to 100
enum NONTERMINALS {
	PRGM = 0,				// Programm
	INSTR_LIST = 1,			// Instruction list
	INSTR = 2,				// Instruction
	ZERO_REG_INSTR = 3,		// Zero register instruction
	ONE_REG_INSTR = 4,		// One register instruction
	TWO_REG_INSTR = 5,		// Two register instruction
	ONE_REG_IMM_INSTR = 6	// One register and immediate value instruction
};

Parser::Parser(LexAnalyzer* analyzer)
{
	this->analyzer = analyzer;
	InitReductionTable();
}

void Parser::Parse()
{
	int top_of_stack = 0;

	if (analyzer == NULL)
		return;

	input_token = analyzer->GetNextToken();

	if (input_token.GetTokenValue() == UNKNOWN)
		ShowError(input_token.GetPosition(), input_token.GetLexeme());

	Shift();

	while(parse_stack[0] != PRGM)
	{
		top_of_stack = (int)(parse_stack.size() - 1);

		switch (parse_stack[top_of_stack])
		{
		case COMMA:
			Shift();
			break;
		case REGISTER:
			if (input_token.GetTokenValue() == COMMA)
				Shift();
			else 
			{
				if (top_of_stack - 1 < 0)
					throw LLDevIOException(STACK_ERROR);

				if (parse_stack[top_of_stack - 1] == ONE_REG_OP)
					Reduce(6);						// reduce one_reg_op reg to one_reg_instr
				else
					Reduce(7);						// reduce two_reg_op reg, reg to two_reg_instr
			}
	
			break;
		case ZERO_REG_OP:							// reduce from zero_reg_op to zero_reg_instr
			Reduce(8);
			break;
		case TWO_REG_OP:
			Shift();
			break;
		case ONE_REG_OP:
			Shift();
			break;
		case ONE_REG_IMM_OP:
			Shift();
			break;
		case IMMEDIATE:								// reduce from one_reg_imm_op reg, imm to one_reg_imm_instr
			Reduce(10);
			break;
		case ONE_REG_IMM_INSTR:						// reduce from one_reg_imm_instr to instr
			Reduce(11);
			break;
		case ZERO_REG_INSTR:						// reduce from zero_reg_instr to instr
			Reduce(9);
			break;
		case TWO_REG_INSTR:
			Reduce(5);								// reduce from two_reg_instr to instr
			break;
		case ONE_REG_INSTR:
			Reduce(4);								// reduce from from one_reg_instr to instr
			break;
		case INSTR:
			Shift();
			break;
		case INSTR_LIST:
			Shift();
			break;
		case END_OF_INPUT:
			if (top_of_stack - 2 < 0 || parse_stack[top_of_stack - 2] != INSTR_LIST)
				Reduce(3);							// reduce from instr EOI to instr_list
			else
				Reduce(2);							// reduce from instr_list EOI instr to instr_list

			break;
		case END_OF_FILE:
			if(parse_stack.size() > 1)
				Reduce(0);							// reduce from instr_list EOF to prgm
			else
				Reduce(1);							// reduce epsilon to prgm

			break;
		default:
			ShowError(input_token.GetPosition(), input_token.GetLexeme());
			break;
		}
	}
}

void Parser::InitReductionTable()
{
	for (int i = 0; i < REDUCT_TABLE_ROWS; i++)
	{
		switch (i)
		{
		case 0:										// prgm -> instr_list eof
			reduct_table[i][0] = INSTR_LIST;
			reduct_table[i][1] = END_OF_FILE;
			reduct_table[i][2] = REDUCT_NONE;
			reduct_table[i][3] = REDUCT_NONE;
			break;
		case 1:										// prgm -> epsilon
			reduct_table[i][0] = END_OF_FILE;
			reduct_table[i][1] = REDUCT_NONE;
			reduct_table[i][2] = REDUCT_NONE;
			reduct_table[i][3] = REDUCT_NONE;
			break;
		case 2:										// instr_list -> instr_list eoi instr
			reduct_table[i][0] = INSTR_LIST;
			reduct_table[i][1] = INSTR;
			reduct_table[i][2] = END_OF_INPUT;
			reduct_table[i][3] = REDUCT_NONE;
			break;
		case 3:										// instr_list -> instr eoi
			reduct_table[i][0] = INSTR;
			reduct_table[i][1] = END_OF_INPUT;
			reduct_table[i][2] = REDUCT_NONE;
			reduct_table[i][3] = REDUCT_NONE;
			break;
		case 4:										// instr -> one_reg_instr
			reduct_table[i][0] = ONE_REG_INSTR;
			reduct_table[i][1] = REDUCT_NONE;
			reduct_table[i][2] = REDUCT_NONE;
			reduct_table[i][3] = REDUCT_NONE;
			break;
		case 5:										// instr -> two_reg_instr
			reduct_table[i][0] = TWO_REG_INSTR;
			reduct_table[i][1] = REDUCT_NONE;
			reduct_table[i][2] = REDUCT_NONE;
			reduct_table[i][3] = REDUCT_NONE;
			break;
		case 6:										// one_reg_instr -> one_reg_op reg
			reduct_table[i][0] = ONE_REG_OP;
			reduct_table[i][1] = REGISTER;
			reduct_table[i][2] = REDUCT_NONE;
			reduct_table[i][3] = REDUCT_NONE;
			break;
		case 7:										// two_reg_instr -> two_reg_instr reg, reg
			reduct_table[i][0] = TWO_REG_OP;
			reduct_table[i][1] = REGISTER;
			reduct_table[i][2] = COMMA;
			reduct_table[i][3] = REGISTER;
			break;
		case 8:										// zero_reg_instr -> zero_reg_op
			reduct_table[i][0] = ZERO_REG_OP;
			reduct_table[i][1] = REDUCT_NONE;
			reduct_table[i][2] = REDUCT_NONE;
			reduct_table[i][3] = REDUCT_NONE;
			break;
		case 9:										// instr -> zero_reg_instr
			reduct_table[i][0] = ZERO_REG_INSTR;
			reduct_table[i][1] = REDUCT_NONE;
			reduct_table[i][2] = REDUCT_NONE;
			reduct_table[i][3] = REDUCT_NONE;
			break;
		case 10:									// one_reg_imm_instr -> one_reg_imm_op reg, imm
			reduct_table[i][0] = ONE_REG_IMM_OP;
			reduct_table[i][1] = REGISTER;
			reduct_table[i][2] = COMMA;
			reduct_table[i][3] = IMMEDIATE;
			break;
		case 11:									// instr -> one_reg_imm_instr
			reduct_table[i][0] = ONE_REG_IMM_INSTR;
			reduct_table[i][1] = REDUCT_NONE;
			reduct_table[i][2] = REDUCT_NONE;
			reduct_table[i][3] = REDUCT_NONE;
			break;
		}
	}
}

void Parser::Shift()
{
	string lexeme = input_token.GetLexeme();
	IMMEDIATE_TYPE imm_type = input_token.GetImmediateType();
	token_pos pos = input_token.GetPosition();

	switch (input_token.GetTokenValue())
	{
	case UNKNOWN:
		ShowError(input_token.GetPosition(), input_token.GetLexeme());
		break;
	case IMMEDIATE:
		if (!IsImmediateCorrect(lexeme, imm_type))
		{
			ShowError(pos, lexeme);
		}
		else
		{
			if (!IsCorrectNumberSize(lexeme, imm_type))
				ShowToLongNumberError(pos, lexeme);
		}
		break;
	default:
		break;
	}

	parse_stack.push_back(input_token.GetTokenValue());
	value_stack.push_back(input_token);

	input_token = analyzer->GetNextToken();
}

void Parser::Reduce(int reduct_table_idx)
{
	int top_of_stack;
	Token token;
	Token* last_token = new Token();
	int lhs = 0;

	for (int i = REDUCT_TABLE_COLS - 1; i >= 0; i--)
	{
		if (reduct_table[reduct_table_idx][i] == REDUCT_NONE)
			continue;

		top_of_stack = (int)(parse_stack.size() - 1);

		if (top_of_stack < 0)
			break;

		if (parse_stack[top_of_stack] == reduct_table[reduct_table_idx][i])
		{
			token = value_stack[top_of_stack];
			*last_token = token;

			switch (parse_stack[top_of_stack])
			{
			case ZERO_REG_OP:
			case ONE_REG_OP:
			case TWO_REG_OP:
			case ONE_REG_IMM_OP:
				code_generator.SetLineNum(token.GetPosition().line_num);
				code_generator.SetOpcodeToken(token);
				break;
			case REGISTER:
				if(parse_stack[top_of_stack - 1] == COMMA)
					code_generator.SetSecondRegisterToken(token);
				else
					code_generator.SetFirstRegisterToken(token);
				break;
			case IMMEDIATE:
				code_generator.SetImmediateToken(token);
				break;
			default:
				break;
			}

			parse_stack.pop_back();
			value_stack.pop_back();
		}			
		else
		{
			token = value_stack[top_of_stack];
			ShowError(token.GetPosition(), token.GetLexeme(),
						parse_stack[top_of_stack], reduct_table[reduct_table_idx][i]);
		}
	}

	switch (reduct_table_idx)
	{
	case 0:
	case 1:
		lhs = PRGM;
		code_generator.EndOfFile();
		code_generator.SaveToFile(analyzer->GetFileName());
		break;
	case 2:
	case 3:
		lhs = INSTR_LIST;
		break;
	case 4:
	case 5:
	case 9:
	case 11:
		code_generator.InitHexLine();
		lhs = INSTR;
		break;
	case 6:
		lhs = ONE_REG_INSTR;
		break;
	case 7:
		lhs = TWO_REG_INSTR;
		break;
	case 8:
		lhs = ZERO_REG_INSTR;
		break;
	case 10:
		lhs = ONE_REG_IMM_INSTR;
		break;
	}

	parse_stack.push_back(lhs);
	value_stack.push_back(*last_token);
	delete last_token;
}

string Parser::LineNumToStr(int line_num)
{
	string ret = "";
	char buffer[4];
	int zeroes_cnt = 0;

	snprintf(buffer, 4, "%d", line_num - 1);

	if (line_num < 10)
		zeroes_cnt = 3;
	else if (line_num < 100)
		zeroes_cnt = 2;
	else if (line_num < 1000)
		zeroes_cnt = 1;

	for (int i = 0; i < zeroes_cnt; i++)
		buffer[i] = '0';

	ret = buffer;

	return ret;
}

void Parser::ShowError(token_pos pos, string lexeme)
{
	char buf[100];

	sprintf_s(buf, "Syntax error at line %d near \"%s\".", pos.line_num, lexeme.c_str());

	throw LLDevIOException(buf);
}

void Parser::ShowError(token_pos pos, string lexeme, int parse_stack_val, int reduct_table_val)
{
	char buf[100];

	if (parse_stack_val == INSTR && reduct_table_val == INSTR_LIST)
		sprintf_s(buf, "Require new line symbol at the end of line %d.", pos.line_num);
	else
		ShowError(pos, lexeme);

	throw LLDevIOException(buf);
}

void Parser::ShowToLongNumberError(token_pos pos, string lexeme)
{
	char buf[100];

	sprintf_s(buf, "Error: to long number at line %d near \"%s\".", pos.line_num, lexeme.c_str());

	throw LLDevIOException(buf);
}

bool Parser::IsImmediateCorrect(string lexeme, IMMEDIATE_TYPE type)
{
	bool ret = false;

	switch (type)
	{
	case DECIMAL:
		ret = IsImmDecimalCorrect(lexeme);
		break;
	case HEXADECIMAL:
		ret = IsImmHexCorrect(lexeme);
		break;
	default:
		break;
	}

	return ret;
}

bool Parser::IsImmDecimalCorrect(string lexeme)
{
	bool ret = true;
	size_t lexeme_size = lexeme.size();
	
	for (unsigned int i = 1; i < lexeme.size(); i++)
	{
		// negative immediate value
		if (i == 1 && lexeme[i] == '-')
		{
			// if there is only minus in lexeme
			if (lexeme.size() < 3)
			{
				ret = false;
				break;
			}			

			continue;
		}			

		ret = IsCorrectNumber(lexeme[i], DECIMAL);
	}

	return ret;
}

bool Parser::IsImmHexCorrect(string lexeme)
{
	bool ret = true;
	size_t lexeme_size = lexeme.size();

	for (unsigned int i = 1; i < lexeme_size; i++)
	{
		// first 2 characters of hex value should be "0x"
		if ((i == 1 && lexeme[i] != '0') || (i == 2 && tolower(lexeme[i]) != 'x'))
		{
			ret = false;
			break;
		}

		if (i == 1 || i == 2)
			continue;

		ret = IsCorrectNumber(lexeme[i], HEXADECIMAL);

		if (!ret)
			break;
	}

	return ret;
}

bool Parser::IsCorrectNumber(char num, IMMEDIATE_TYPE type)
{
	bool ret = false;
	int max_i;

	switch (type)
	{
	case HEXADECIMAL:
		max_i = 16;
		break;
	default:
		max_i = 10;
		break;
	}

	for (int i = 0; i < max_i; i++)
	{
		if (tolower(num) == imm_digits[i])
		{
			ret = true;
			break;
		}
	}

	return ret;
}

bool Parser::IsCorrectNumberSize(string lexeme, IMMEDIATE_TYPE type)
{
	bool ret = false;
	string num_to_convert = lexeme.substr(1, lexeme.size() - 1);
	uint32_t int_val;

	switch (type)
	{
	case HEXADECIMAL:
		if (num_to_convert.size() > 8)
			return false;

		int_val = stoi(num_to_convert, NULL, 16);
		break;
	default:
		if (num_to_convert.size() > 7)
			return false;

		int_val = stoi(num_to_convert);
		break;
	}

	return int_val <= MAX_IMM_VALUE;
}
