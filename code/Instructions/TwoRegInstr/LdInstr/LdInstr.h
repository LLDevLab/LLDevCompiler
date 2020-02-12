#pragma once

#include "../TwoRegInstr.h"

using namespace std;

class LdInstr: public TwoRegInstr
{
public:
	LdInstr(uint line_num);
	uint32_t GetOpcode();
};