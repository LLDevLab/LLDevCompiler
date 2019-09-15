#pragma once

#include "../TwoRegInstr.h"

using namespace std;

class SubInstr: public TwoRegInstr
{
public:
	SubInstr(unsigned int line_num);
	uint32_t GetOpcode();
};