#pragma once

#include "../OneRegInstr.h"

using namespace std;

class BrgtuInstr: public OneRegInstr
{
public:
	BrgtuInstr(unsigned int line_num);
	uint32_t GetOpcode();
};