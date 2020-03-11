#pragma once

#include "../TwoRegInstr.h"

using namespace std;

class XorInstr: public TwoRegInstr
{
public:
	XorInstr(token_pos pos);
	uint32_t GetOpcode();
};