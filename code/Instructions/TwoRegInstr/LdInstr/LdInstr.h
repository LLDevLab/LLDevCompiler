#pragma once

#include "../TwoRegInstr.h"

using namespace std;

class LdInstr: public TwoRegInstr
{
public:
	LdInstr(unsigned int line_num);
	uint32_t GetOpcode();
};