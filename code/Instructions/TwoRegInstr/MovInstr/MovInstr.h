#pragma once

#include "../TwoRegInstr.h"

using namespace std;

class MovInstr: public TwoRegInstr
{
public:
	MovInstr(unsigned int line_num);
	uint32_t GetOpcode();
};