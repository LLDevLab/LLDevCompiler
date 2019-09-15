#pragma once

#include "../TwoRegInstr.h"

using namespace std;

class XorInstr: public TwoRegInstr
{
public:
	XorInstr(unsigned int line_num);
	uint32_t GetOpcode();
};