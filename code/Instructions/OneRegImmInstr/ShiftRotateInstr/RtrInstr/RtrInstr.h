#pragma once

#include "../ShiftRotateInstr.h"

using namespace std;

class RtrInstr: public ShiftRotateInstr
{
public:
	RtrInstr(uint line_num);
	uint32_t GetOpcode();
};