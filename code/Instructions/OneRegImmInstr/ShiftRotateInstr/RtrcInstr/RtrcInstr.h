#pragma once

#include "../ShiftRotateInstr.h"

using namespace std;

class RtrcInstr: public ShiftRotateInstr
{
public:
	RtrcInstr(uint line_num);
	uint32_t GetOpcode();
};