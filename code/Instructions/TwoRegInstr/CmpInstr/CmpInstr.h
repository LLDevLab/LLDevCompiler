#pragma once

#include "../TwoRegInstr.h"

using namespace std;

class CmpInstr: public TwoRegInstr
{
public:
	CmpInstr(token_pos pos);
	uint32_t GetOpcode();
};