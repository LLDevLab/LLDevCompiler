#pragma once

#include "../ShiftRotateInstr.h"

using namespace std;

class RtrInstr: public ShiftRotateInstr
{
public:
	RtrInstr(token_pos pos);
	uint32_t GetOpcode();
};