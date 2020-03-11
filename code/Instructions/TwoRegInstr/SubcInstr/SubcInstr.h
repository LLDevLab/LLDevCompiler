#pragma once

#include "../TwoRegInstr.h"

using namespace std;

class SubcInstr: public TwoRegInstr
{
public:
	SubcInstr(token_pos pos);
	uint32_t GetOpcode();
};