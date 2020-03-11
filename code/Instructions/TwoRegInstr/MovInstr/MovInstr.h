#pragma once

#include "../TwoRegInstr.h"

using namespace std;

class MovInstr: public TwoRegInstr
{
public:
	MovInstr(token_pos pos);
	uint32_t GetOpcode();
};