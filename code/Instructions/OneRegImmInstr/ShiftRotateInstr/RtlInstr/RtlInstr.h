#pragma once

#include "../ShiftRotateInstr.h"

using namespace std;

class RtlInstr: public ShiftRotateInstr
{
public:
	RtlInstr(token_pos pos);
	uint32_t GetOpcode();
};