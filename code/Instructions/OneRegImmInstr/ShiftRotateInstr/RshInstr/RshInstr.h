#pragma once

#include "../ShiftRotateInstr.h"

using namespace std;

class RshInstr: public ShiftRotateInstr
{
public:
	RshInstr(token_pos pos);
	uint32_t GetOpcode();
};