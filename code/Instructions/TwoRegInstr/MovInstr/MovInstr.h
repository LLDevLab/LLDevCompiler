#pragma once

#include "../TwoRegInstr.h"

using namespace std;

class MovInstr: public TwoRegInstr
{
public:
	MovInstr(uint line_num);
	uint32_t GetOpcode();
};