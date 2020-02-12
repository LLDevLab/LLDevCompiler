#pragma once

#include "../TwoRegInstr.h"

using namespace std;

class AddInstr: public TwoRegInstr
{
public:
	AddInstr(uint line_num);
	uint32_t GetOpcode();
};