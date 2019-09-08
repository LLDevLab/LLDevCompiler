#pragma once

#include <string>
#include <sstream>				// string stream
#include <fstream>
#include "../LexAnalyzer/LexAnalyzer.h"

#define REG_ADDR_MAX 15
#define OUTPUT_FILE_EXT ".hex"
#define HEX_DATA_SIZE "04"
#define HEX_DATA_TYPE "00"
#define DATA_STR_SIZE 8

using namespace std;

class CodeGenerator
{
public:
	CodeGenerator();
	void EndOfFile();
	void SetLineNum(int line_num);
	void SetOpcodeToken(Token token);
	void SetFirstRegisterToken(Token token);
	void SetSecondRegisterToken(Token token);
	void SetImmediateToken(Token token);
	void SaveToFile(const char* file);
	void InitHexLine();
private:
	string hex_line;
	string hex_file;

	uint32_t opcode_bin;
	uint32_t reg1_bin;
	uint32_t reg2_bin;
	uint32_t imm_bin;

	bool is_reg1_set;
	bool is_reg2_set;
	bool is_imm_set;

	string LineNumToStr(int line_num);
	void ClearBinaries();
	void ClearHexs();
	uint32_t GetOpcodeBin(string lexeme);
	uint32_t GetRegisterBin(string lexeme);
	string ConvertBinsToHex();
	string GetCheckSum();
	void SaveLine();	
	string RemoveFileExtension(const char* file_name);
	int HexStrToInt(string hex_str);
};