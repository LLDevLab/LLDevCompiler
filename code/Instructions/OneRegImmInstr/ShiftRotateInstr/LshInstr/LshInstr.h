#pragma once

#include "../ShiftRotateInstr.h"

using namespace std;

class LshInstr: public ShiftRotateInstr
{
public:
	LshInstr(token_pos pos);
	uint32_t GetOpcode();
};