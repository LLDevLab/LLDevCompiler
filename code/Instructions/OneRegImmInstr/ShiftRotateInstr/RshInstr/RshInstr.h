#pragma once

#include "../ShiftRotateInstr.h"

using namespace std;

class RshInstr: public ShiftRotateInstr
{
public:
	RshInstr(unsigned int line_num);
	uint32_t GetOpcode();
};