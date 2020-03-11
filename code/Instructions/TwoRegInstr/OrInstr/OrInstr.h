#pragma once

#include "../TwoRegInstr.h"

using namespace std;

class OrInstr: public TwoRegInstr
{
public:
	OrInstr(token_pos pos);
	uint32_t GetOpcode();
};