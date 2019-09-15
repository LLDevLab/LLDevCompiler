#pragma once

#include "../OneRegInstr.h"

using namespace std;

class BrltsInstr: public OneRegInstr
{
public:
	BrltsInstr(unsigned int line_num);
	uint32_t GetOpcode();
};