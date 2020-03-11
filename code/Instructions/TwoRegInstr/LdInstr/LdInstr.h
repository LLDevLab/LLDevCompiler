#pragma once

#include "../TwoRegInstr.h"

using namespace std;

class LdInstr: public TwoRegInstr
{
public:
	LdInstr(token_pos pos);
	uint32_t GetOpcode();
};