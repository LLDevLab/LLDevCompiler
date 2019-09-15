#pragma once

#include "../OneRegInstr.h"

using namespace std;

class BreqInstr: public OneRegInstr
{
public:
	BreqInstr(unsigned int line_num);
	uint32_t GetOpcode();
};