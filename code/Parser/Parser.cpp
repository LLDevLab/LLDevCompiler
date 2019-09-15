#include "Parser.h"

#define REDUCT_NONE -1
#define REDUCT_ERROR -2
#define STACK_ERROR "Stack out of range."

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
	switch (input_token.GetTokenValue())
	{
	case UNKNOWN:
		ShowError(input_token.GetPosition(), input_token.GetLexeme());
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
	string cur_lexeme = "";
	token_pos cur_pos;
	string first_reg = "";
	string second_reg = "";
	string immediate = "";
	Instruction *cur_instr = NULL;
	TwoRegInstr *twoRegInstr = NULL;
	OneRegInstr *oneRegInstr = NULL;
	OneRegImmInstr *oneRegImmInstr = NULL;

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
			cur_lexeme = token.GetLexeme();
			cur_pos = token.GetPosition();

			*last_token = token;

			switch (parse_stack[top_of_stack])
			{
			case ZERO_REG_OP:
				cur_instr = CreateZeroRegInstr(cur_lexeme, cur_pos.line_num);

				if (cur_instr != NULL)
					code_generator.SetInstruction(cur_instr);

				break;
			case ONE_REG_OP:
				cur_instr = CreateOneRegInstr(cur_lexeme, cur_pos.line_num);

				if (cur_instr != NULL)
				{
					oneRegInstr = (OneRegInstr*)cur_instr;
					oneRegInstr->SetFirstReg(first_reg);

					code_generator.SetInstruction(cur_instr);
				}				

				break;
			case TWO_REG_OP:
				cur_instr = CreateTwoRegInstr(cur_lexeme, cur_pos.line_num);

				if (cur_instr != NULL)
				{
					twoRegInstr = (TwoRegInstr*)cur_instr;
					twoRegInstr->SetFirstReg(first_reg);
					twoRegInstr->SetSecondReg(second_reg);

					code_generator.SetInstruction(cur_instr);
				}

				break;
			case ONE_REG_IMM_OP:
				cur_instr = CreateOneRegImmInstr(cur_lexeme, cur_pos.line_num);

				if (cur_instr != NULL)
				{
					oneRegImmInstr = (OneRegImmInstr*)cur_instr;
					oneRegImmInstr->SetFirstReg(first_reg);
					oneRegImmInstr->SetImmediateValue(immediate);

					code_generator.SetInstruction(oneRegImmInstr);
				}

				break;
			case REGISTER:
				if (parse_stack[top_of_stack - 1] == COMMA)
					second_reg = token.GetLexeme();
				else
					first_reg = token.GetLexeme();
				break;
			case IMMEDIATE:
				immediate = token.GetLexeme();
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
			ShowError(token.GetPosition(), cur_lexeme, parse_stack[top_of_stack], reduct_table[reduct_table_idx][i]);
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

void Parser::ShowError(token_pos pos, string lexeme, int parse_stack_val, int reduct_table_val)
{
	char buf[100];

	if (parse_stack_val == INSTR && reduct_table_val == INSTR_LIST)
	{
		sprintf_s(buf, "Require new line symbol at the end of line %d.", pos.line_num);
		throw LLDevIOException(buf);
	}
	else
		ShowError(pos, lexeme);
}

void Parser::ShowError(token_pos pos, string lexeme)
{
	char buf[100];

	sprintf_s(buf, "Unexpected token %s at line %d.", lexeme.c_str(), pos.line_num);

	throw LLDevIOException(buf);
}

inline Instruction* Parser::CreateZeroRegInstr(string lexeme, unsigned int line_num)
{
	Instruction *ret = NULL;

	if (lexeme == "noop")
		ret = new NoopInstr(line_num);

	return ret;
}

inline Instruction* Parser::CreateOneRegInstr(string lexeme, unsigned int line_num)
{
	Instruction *ret = NULL;

	if (lexeme == "br")
		ret = new BrInstr(line_num);
	else if (lexeme == "breq")
		ret = new BreqInstr(line_num);
	else if (lexeme == "brne")
		ret = new BrneInstr(line_num);
	else if (lexeme == "brlts")
		ret = new BrltsInstr(line_num);
	else if (lexeme == "brgts")
		ret = new BrgtsInstr(line_num);
	else if (lexeme == "brltu")
		ret = new BrltuInstr(line_num);
	else if (lexeme == "brgtu")
		ret = new BrgtuInstr(line_num);
	else if (lexeme == "clr")
		ret = new ClrInstr(line_num);
	else if (lexeme == "not")
		ret = new NotInstr(line_num);

	return ret;
}

inline Instruction* Parser::CreateTwoRegInstr(string lexeme, unsigned int line_num)
{
	Instruction *ret = NULL;

	if (lexeme == "add")
		ret = new AddInstr(line_num);
	else if (lexeme == "sub")
		ret = new SubInstr(line_num);
	else if (lexeme == "cmp")
		ret = new CmpInstr(line_num);
	else if (lexeme == "or")
		ret = new OrInstr(line_num);
	else if (lexeme == "and")
		ret = new AndInstr(line_num);
	else if (lexeme == "xor")
		ret = new XorInstr(line_num);

	return ret;
}

inline Instruction* Parser::CreateOneRegImmInstr(string lexeme, unsigned int line_num)
{
	Instruction *ret = NULL;

	if (lexeme == "ldi")
		ret = new LdiInstr(line_num);

	return ret;
}
