#pragma once

#include "../ShiftRotateInstr.h"

using namespace std;

class RtlcInstr: public ShiftRotateInstr
{
public:
	RtlcInstr(unsigned int line_num);
	uint32_t GetOpcode();
};