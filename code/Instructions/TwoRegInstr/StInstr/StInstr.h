#pragma once

#include "../TwoRegInstr.h"

using namespace std;

class StInstr: public TwoRegInstr
{
public:
	StInstr(token_pos pos);
	uint32_t GetOpcode();
};