#pragma once

#include "../OneRegInstr.h"

using namespace std;

class PushInstr: public OneRegInstr
{
public:
	PushInstr(unsigned int line_num);
	uint32_t GetOpcode();
};