#pragma once

#include "../TwoRegInstr.h"

using namespace std;

class SubcInstr: public TwoRegInstr
{
public:
	SubcInstr(uint line_num);
	uint32_t GetOpcode();
};