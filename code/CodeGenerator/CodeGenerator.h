#pragma once

#include <string>
#include <sstream>				// string stream
#include <fstream>
#include "../LexAnalyzer/LexAnalyzer.h"
#include "../Parser/Nonterminals.h"
#include "../Instructions/Instruction.h"
#include "../Instructions/ZeroRegInstr/ZeroRegInstr.h"
#include "../Instructions/OneRegImmInstr/OneRegImmInstr.h"
#include "../Instructions/OneRegInstr/OneRegInstr.h"
#include "../Instructions/TwoRegInstr/TwoRegInstr.h"

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
	void SaveToFile(const char* file);
	void InitHexLine();
	void SetInstruction(Instruction* instruction);
private:
	string hex_line;
	string hex_file;

	Instruction *instruction;

	string LineNumToStr(unsigned int line_num);
	void ClearHexs();
	string ConvertBinsToHex();
	string GetCheckSum();
	void SaveLine();	
	string RemoveFileExtension(const char* file_name);
	int HexStrToInt(string hex_str);
	uint32_t GetInstructionOpcode();
	uint32_t GetFirstRegAddr();
	uint32_t GetSecondRegAddr();
	uint32_t GetImmediateValue();
	uint32_t GetImmediateShiftingPos();
};