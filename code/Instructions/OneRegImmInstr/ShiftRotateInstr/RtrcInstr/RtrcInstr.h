#pragma once

#include "../ShiftRotateInstr.h"

using namespace std;

class RtrcInstr: public ShiftRotateInstr
{
public:
	RtrcInstr(token_pos pos);
	uint32_t GetOpcode();
};