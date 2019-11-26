#pragma once

#include "../OneRegInstr.h"

using namespace std;

class PopInstr: public OneRegInstr
{
public:
	PopInstr(unsigned int line_num);
	uint32_t GetOpcode();
};