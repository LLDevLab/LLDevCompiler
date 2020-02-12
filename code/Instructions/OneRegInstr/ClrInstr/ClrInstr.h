#pragma once

#include "../OneRegInstr.h"

using namespace std;

class ClrInstr: public OneRegInstr
{
public:
	ClrInstr(uint line_num);
	uint32_t GetOpcode();
};