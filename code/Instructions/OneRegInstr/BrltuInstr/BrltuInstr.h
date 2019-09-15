#pragma once

#include "../OneRegInstr.h"

using namespace std;

class BrltuInstr: public OneRegInstr
{
public:
	BrltuInstr(unsigned int line_num);
	uint32_t GetOpcode();
};