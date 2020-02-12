#pragma once

#include "../OneRegInstr.h"

using namespace std;

class BreqInstr: public OneRegInstr
{
public:
	BreqInstr(uint line_num);
	uint32_t GetOpcode();
};