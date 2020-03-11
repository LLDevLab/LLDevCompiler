#pragma once

#include "../ShiftRotateInstr.h"

using namespace std;

class RtlcInstr: public ShiftRotateInstr
{
public:
	RtlcInstr(token_pos pos);
	uint32_t GetOpcode();
};