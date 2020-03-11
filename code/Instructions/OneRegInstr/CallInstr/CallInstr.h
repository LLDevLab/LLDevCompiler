#pragma once

#include "../OneRegInstr.h"

using namespace std;

class CallInstr: public OneRegInstr
{
public:
	CallInstr(token_pos pos);
	uint32_t GetOpcode();
};