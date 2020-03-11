#pragma once

#include "../TwoRegInstr.h"

using namespace std;

class AndInstr: public TwoRegInstr
{
public:
	AndInstr(token_pos pos);
	uint32_t GetOpcode();
};