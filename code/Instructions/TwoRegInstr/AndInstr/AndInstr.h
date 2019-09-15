#pragma once

#include "../TwoRegInstr.h"

using namespace std;

class AndInstr: public TwoRegInstr
{
public:
	AndInstr(unsigned int line_num);
	uint32_t GetOpcode();
};