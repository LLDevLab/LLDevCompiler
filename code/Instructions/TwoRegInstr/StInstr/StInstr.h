#pragma once

#include "../TwoRegInstr.h"

using namespace std;

class StInstr: public TwoRegInstr
{
public:
	StInstr(unsigned int line_num);
	uint32_t GetOpcode();
};