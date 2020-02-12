#pragma once

#include "../ShiftRotateInstr.h"

using namespace std;

class RshInstr: public ShiftRotateInstr
{
public:
	RshInstr(uint line_num);
	uint32_t GetOpcode();
};