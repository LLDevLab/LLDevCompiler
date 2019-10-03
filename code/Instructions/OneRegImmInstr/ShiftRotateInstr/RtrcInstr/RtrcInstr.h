#pragma once

#include "../ShiftRotateInstr.h"

using namespace std;

class RtrcInstr: public ShiftRotateInstr
{
public:
	RtrcInstr(unsigned int line_num);
	uint32_t GetOpcode();
};