#pragma once

#include "../TwoRegInstr.h"

using namespace std;

class AndInstr: public TwoRegInstr
{
public:
	AndInstr(uint line_num);
	uint32_t GetOpcode();
};