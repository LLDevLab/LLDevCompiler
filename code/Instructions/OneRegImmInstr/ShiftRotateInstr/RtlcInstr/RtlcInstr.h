#pragma once

#include "../ShiftRotateInstr.h"

using namespace std;

class RtlcInstr: public ShiftRotateInstr
{
public:
	RtlcInstr(uint line_num);
	uint32_t GetOpcode();
};