#pragma once

#include "../OneRegInstr.h"

using namespace std;

class NotInstr: public OneRegInstr
{
public:
	NotInstr(unsigned int line_num);
	uint32_t GetOpcode();
};