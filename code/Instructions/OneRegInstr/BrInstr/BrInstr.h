#pragma once

#include "../OneRegInstr.h"

using namespace std;

class BrInstr: public OneRegInstr
{
public:
	BrInstr(unsigned int line_num);
	uint32_t GetOpcode();
};