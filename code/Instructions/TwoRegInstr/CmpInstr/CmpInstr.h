#pragma once

#include "../TwoRegInstr.h"

using namespace std;

class CmpInstr: public TwoRegInstr
{
public:
	CmpInstr(unsigned int line_num);
	uint32_t GetOpcode();
};