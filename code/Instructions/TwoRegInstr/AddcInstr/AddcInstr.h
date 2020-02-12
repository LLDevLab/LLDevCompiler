#pragma once

#include "../TwoRegInstr.h"

using namespace std;

class AddcInstr: public TwoRegInstr
{
public:
	AddcInstr(uint line_num);
	uint32_t GetOpcode();
};