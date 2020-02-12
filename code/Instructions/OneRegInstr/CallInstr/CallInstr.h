#pragma once

#include "../OneRegInstr.h"

using namespace std;

class CallInstr: public OneRegInstr
{
public:
	CallInstr(uint line_num);
	uint32_t GetOpcode();
};