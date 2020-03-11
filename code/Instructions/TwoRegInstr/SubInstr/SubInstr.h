#pragma once

#include "../TwoRegInstr.h"

using namespace std;

class SubInstr: public TwoRegInstr
{
public:
	SubInstr(token_pos pos);
	uint32_t GetOpcode();
};