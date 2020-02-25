#include "LexAnalyzer.h"

LexAnalyzer::LexAnalyzer(string file, SymbolTable* symbol_table)
{
	cur_line = 0;
	cur_bytecode_line = 0;
	cur_token_index = 0;
	file_name = file;
	this->symbol_table = symbol_table;

	OpenFile();
	GetLexemes(ReadLine());
}

LexAnalyzer::~LexAnalyzer()
{
	if(ios_file.is_open())
		ios_file.close();
}

Token LexAnalyzer::GetNextToken()
{
	Token ret;
	string cur_lexeme = "";
	token_pos pos;
	TOKENS tokens;

	pos.line_num = cur_line;
	pos.bytecode_line_num = cur_bytecode_line;

	if (cur_token_index < lexemes.size())
	{
		cur_lexeme = lexemes[cur_token_index];
		cur_token_index++;

		SetTokenLexeme(&ret, cur_lexeme);
		ret.SetTokenPos(pos);

		tokens = GetTokenFromLexeme(cur_lexeme);

		ret.SetTokenValue(tokens);
	}
	else
	{
		if (ios_file.eof())
			ret.SetTokenValue(END_OF_FILE);
		else
		{
			ret.SetTokenValue(END_OF_INPUT);
			GetLexemes(ReadLine());
		}			
	}

	return ret;
}

string LexAnalyzer::GetFileName()
{
	return file_name;
}

string LexAnalyzer::ReadLine()
{
	string ret = "";

	do
	{
		cur_line++;
		getline(ios_file, ret);

	} while (!ios_file.eof() && ret == "");			// ignore empty lines

	return ret;
}

void LexAnalyzer::GetLexemes(string line)
{
	size_t cur_pos = 0;
	size_t prev_pos = 0;
	string lexeme = "";
	string tmp_line;

	tmp_line = GetNextValidLine(line);
	
	cur_bytecode_line++;

	lexemes.clear();
	cur_token_index = 0;

	if (tmp_line == "")
		return;

	cur_pos = tmp_line.find(token_delim);

	while (cur_pos != string::npos)
	{
		lexeme = tmp_line.substr(prev_pos, cur_pos - prev_pos);

		AddLexeme(lexeme,(int)(prev_pos + 1));

		prev_pos = cur_pos + 1;
		cur_pos = tmp_line.find(token_delim, prev_pos);

		if (cur_pos < 0)
			break;
	}

	lexeme = tmp_line.substr(prev_pos, cur_pos - prev_pos);

	if(lexeme != "")
		AddLexeme(lexeme, (int)prev_pos + 1);
}

string LexAnalyzer::GetNextValidLine(string str_line)
{
	string ret = str_line;

	while (LineHelper::CanSkip(ret))
	{
		ret = ReadLine();
	}

	return ret;
}

void LexAnalyzer::AddLexeme(string lexeme, int pos)
{
	string lexeme_last_sym = "";
	size_t lexeme_size = 0;

	lexeme_size = lexeme.size();
	lexeme_last_sym = lexeme.substr(lexeme_size - 1, 1);

	if (lexeme_last_sym == ",")
	{
		lexemes.push_back(lexeme.substr(0, lexeme_size - 1));

		lexemes.push_back(lexeme_last_sym);
	}
	else
	{
		lexemes.push_back(lexeme);
	}		
}

TOKENS LexAnalyzer::GetTokenFromLexeme(string lexeme)
{
	TOKENS ret = UNKNOWN;

	if (IsTwoRegOp(lexeme))
		ret = TWO_REG_OP;
	else if (IsOneRegOp(lexeme))
		ret = ONE_REG_OP;
	else if (IsRegister(lexeme))
		ret = REGISTER;
	else if (lexeme == ",")
		ret = COMMA;
	else if (IsZeroRegOp(lexeme))
		ret = ZERO_REG_OP;
	else if (IsOneRegImmOp(lexeme))
		ret = ONE_REG_IMM_OP;
	else if (IsImmediate(lexeme) || symbol_table->SymbolExist(lexeme))
		ret = IMMEDIATE;

	return ret;
}

inline bool LexAnalyzer::IsZeroRegOp(string lexeme)
{
	return lexeme == "noop" ||
		lexeme == "ret";
}

inline bool LexAnalyzer::IsTwoRegOp(string lexeme)
{
	return lexeme == "add" ||
		lexeme == "sub" ||
		lexeme == "cmp" ||
		lexeme == "or" ||
		lexeme == "and" ||
		lexeme == "xor" ||
		lexeme == "addc" ||
		lexeme == "subc" ||
		lexeme == "ld" ||
		lexeme == "st" ||
		lexeme == "mov";
}

inline bool LexAnalyzer::IsOneRegOp(string lexeme)
{
	return lexeme == "br" ||
			lexeme == "breq" ||
			lexeme == "brne" ||
			lexeme == "brlts" ||
			lexeme == "brgts" ||
			lexeme == "brltu" ||
			lexeme == "brgtu" ||
			lexeme == "clr" ||
			lexeme == "not" ||
			lexeme == "push" ||
			lexeme == "pop" ||
			lexeme == "call";
}

inline bool LexAnalyzer::IsOneRegImmOp(string lexeme)
{
	return lexeme == "ldi" ||
		lexeme == "lsh" ||
		lexeme == "rsh" ||
		lexeme == "rtl" ||
		lexeme == "rtr" ||
		lexeme == "rtlc" ||
		lexeme == "rtrc";
}

inline bool LexAnalyzer::IsImmediate(string lexeme)
{
	return lexeme[0] == '#';
}

bool LexAnalyzer::IsRegister(string lexeme)
{
	bool ret = false;
	string reg_lexeme = "";
	const int buf_size = 4;
	char buffer[buf_size] = "\0";

	if (lexeme.size() <= 1)
		return false;

	for (int i = 0; i < 16; i++)
	{
		reg_lexeme = "r";

		snprintf(buffer, buf_size, "%d", i);
		reg_lexeme += buffer[0];
		
		if (i >= 10)
			reg_lexeme += buffer[1];

		if (reg_lexeme == lexeme)
		{
			ret = true;
			break;
		}
	}

	return ret;
}

void LexAnalyzer::SetTokenLexeme(Token* token, string lexeme)
{
	int elem;
	string new_lexeme = lexeme;
	const int buf_len = 8;
	char buf[buf_len];

	if (symbol_table->SymbolExist(lexeme))
	{
		elem = symbol_table->GetSymbolPos(lexeme);
		_itoa_s(elem, buf, buf_len, 10);
		new_lexeme = '#';
		new_lexeme.append(buf);
	}

	token->SetLexeme(new_lexeme);
}

inline void LexAnalyzer::OpenFile()
{
	ios_file.open(file_name);

	if (!ios_file.is_open())
		throw exception("File is not open.");
}
