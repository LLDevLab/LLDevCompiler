#pragma once

#include "../OneRegImmInstr.h"

using namespace std;

class LshInstr: public OneRegImmInstr
{
public:
	LshInstr(unsigned int line_num);
	uint32_t GetOpcode();
	uint32_t GetShiftingPos();
protected:
	int GetMaxImmValue();
	int GetMinImmValue();
	unsigned int GetMaxImmStrSize();
};