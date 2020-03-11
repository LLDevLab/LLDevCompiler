#pragma once

#include "../TwoRegInstr.h"

using namespace std;

class AddInstr: public TwoRegInstr
{
public:
	AddInstr(token_pos pos);
	uint32_t GetOpcode();
};