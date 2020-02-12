#pragma once

#include "../OneRegInstr.h"

using namespace std;

class BrgtuInstr: public OneRegInstr
{
public:
	BrgtuInstr(uint line_num);
	uint32_t GetOpcode();
};