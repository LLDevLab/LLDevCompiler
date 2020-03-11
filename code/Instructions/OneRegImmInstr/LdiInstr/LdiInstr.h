#pragma once

#include "../OneRegImmInstr.h"

using namespace std;

class LdiInstr: public OneRegImmInstr
{
public:
	LdiInstr(token_pos pos);
	uint32_t GetOpcode();
	uint32_t GetShiftingPos();
protected:
	int GetMaxImmValue();
	int GetMinImmValue();
	uint GetMaxImmStrSize();
};