#pragma once

#include "../TwoRegInstr.h"

using namespace std;

class SubcInstr: public TwoRegInstr
{
public:
	SubcInstr(unsigned int line_num);
	uint32_t GetOpcode();
};