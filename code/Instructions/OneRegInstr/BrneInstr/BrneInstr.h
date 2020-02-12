#pragma once

#include "../OneRegInstr.h"

using namespace std;

class BrneInstr: public OneRegInstr
{
public:
	BrneInstr(uint line_num);
	uint32_t GetOpcode();
};