#pragma once

#include "../TwoRegInstr.h"

using namespace std;

class OrInstr: public TwoRegInstr
{
public:
	OrInstr(uint line_num);
	uint32_t GetOpcode();
};