#pragma once

#include "../OneRegInstr.h"

using namespace std;

class BrgtsInstr: public OneRegInstr
{
public:
	BrgtsInstr(unsigned int line_num);
	uint32_t GetOpcode();
};