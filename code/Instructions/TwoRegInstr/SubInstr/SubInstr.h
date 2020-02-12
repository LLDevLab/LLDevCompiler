#pragma once

#include "../TwoRegInstr.h"

using namespace std;

class SubInstr: public TwoRegInstr
{
public:
	SubInstr(uint line_num);
	uint32_t GetOpcode();
};