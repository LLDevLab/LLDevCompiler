#pragma once

#include "../OneRegInstr.h"

using namespace std;

class PopInstr: public OneRegInstr
{
public:
	PopInstr(uint line_num);
	uint32_t GetOpcode();
};