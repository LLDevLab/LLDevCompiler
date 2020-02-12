#pragma once

#include "../TwoRegInstr.h"

using namespace std;

class StInstr: public TwoRegInstr
{
public:
	StInstr(uint line_num);
	uint32_t GetOpcode();
};