#pragma once

#include "../ShiftRotateInstr.h"

using namespace std;

class RtlInstr: public ShiftRotateInstr
{
public:
	RtlInstr(uint line_num);
	uint32_t GetOpcode();
};