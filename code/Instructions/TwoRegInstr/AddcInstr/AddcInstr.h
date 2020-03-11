#pragma once

#include "../TwoRegInstr.h"

using namespace std;

class AddcInstr: public TwoRegInstr
{
public:
	AddcInstr(token_pos pos);
	uint32_t GetOpcode();
};