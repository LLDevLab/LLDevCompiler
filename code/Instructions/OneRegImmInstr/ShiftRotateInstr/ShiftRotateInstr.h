#pragma once

#include "../OneRegImmInstr.h"

using namespace std;

class ShiftRotateInstr: public OneRegImmInstr
{
public:
	virtual uint32_t GetOpcode() = 0;
	virtual uint32_t GetShiftingPos();
protected:
	ShiftRotateInstr(token_pos pos);
	virtual int GetMaxImmValue();
	virtual int GetMinImmValue();
	virtual uint GetMaxImmStrSize();
};