#pragma once

#include "../TwoRegInstr.h"

using namespace std;

class AddInstr: public TwoRegInstr
{
public:
	AddInstr(unsigned int line_num);
	uint32_t GetOpcode();
};