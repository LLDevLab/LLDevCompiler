#pragma once

#include "../OneRegInstr.h"

using namespace std;

class BrneInstr: public OneRegInstr
{
public:
	BrneInstr(unsigned int line_num);
	uint32_t GetOpcode();
};