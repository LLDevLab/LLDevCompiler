#pragma once

#include "../OneRegInstr.h"

using namespace std;

class PushInstr: public OneRegInstr
{
public:
	PushInstr(uint line_num);
	uint32_t GetOpcode();
};