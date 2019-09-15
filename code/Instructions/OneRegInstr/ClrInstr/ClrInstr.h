#pragma once

#include "../OneRegInstr.h"

using namespace std;

class ClrInstr: public OneRegInstr
{
public:
	ClrInstr(unsigned int line_num);
	uint32_t GetOpcode();
};