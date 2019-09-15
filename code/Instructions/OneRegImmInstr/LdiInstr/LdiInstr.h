#pragma once

#include "../OneRegImmInstr.h"

using namespace std;

class LdiInstr: public OneRegImmInstr
{
public:
	LdiInstr(unsigned int line_num);
	uint32_t GetOpcode();
	uint32_t GetShiftingPos();
protected:
	int GetMaxImmValue();
	int GetMinImmValue();
	unsigned int GetMaxImmStrSize();
};