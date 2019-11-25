#include "LexAnalyzer.h"

LexAnalyzer::LexAnalyzer(const char* file)
{
	cur_line = 0;
	cur_code_line = 0;
	cur_pos = 0;
	cur_token_index = 0;
	file_name = file;

	ios_file.open(file_name);
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
	int line_pos = 0;
	token_pos pos;
	TOKENS tokens;

	pos.line_num = cur_line;
	pos.code_line_num = cur_code_line;

	if (cur_token_index < lexemes.size())
	{
		cur_lexeme = lexemes[cur_token_index];
		line_pos = lex_positions[cur_token_index];
		cur_token_index++;

		ret.SetLexeme(cur_lexeme);
		pos.line_pos = line_pos;
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

const char* LexAnalyzer::GetFileName()
{
	return file_name;
}

string LexAnalyzer::ReadLine()
{
	string ret = "";

	if (ios_file.bad() || ios_file.fail())
		throw exception("File is not open.");

	do
	{
		cur_line++;
		getline(ios_file, ret);

	} while (!ios_file.eof() && ret == "");			// ignore empty lines

	return ret;
}

void LexAnalyzer::GetLexemes(string line)
{
	int cur_pos = 0;
	int prev_pos = 0;
	string lexeme = "";
	string tmp_line;

	tmp_line = SkipComments(line);
	
	cur_code_line++;

	lexemes.clear();
	cur_token_index = 0;

	lex_positions.clear();

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

/// Skips all comment lines and return next line of code
string LexAnalyzer::SkipComments(string str_line)
{
	string ret = str_line;

	while (IsComment(ret))
		ret = ReadLine();

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
		lex_positions.push_back(pos - 1);

		lexemes.push_back(lexeme_last_sym);
		lex_positions.push_back(pos);
	}
	else
	{
		lexemes.push_back(lexeme);
		lex_positions.push_back(pos);
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
	else if (IsImmediate(lexeme))
		ret = IMMEDIATE;

	return ret;
}

inline bool LexAnalyzer::IsZeroRegOp(string lexeme)
{
	return lexeme == "noop";
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
			lexeme == "push";
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

inline bool LexAnalyzer::IsComment(string str_line)
{
	return (str_line.length() > 1 && str_line.substr(0, 2) == "//");
}
