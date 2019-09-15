#pragma once

#include "../ShiftRotateInstr.h"

using namespace std;

class LshInstr: public ShiftRotateInstr
{
public:
	LshInstr(unsigned int line_num);
	uint32_t GetOpcode();
};