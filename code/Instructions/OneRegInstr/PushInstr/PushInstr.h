#pragma once

#include "../OneRegInstr.h"

using namespace std;

class PushInstr: public OneRegInstr
{
public:
	PushInstr(token_pos pos);
	uint32_t GetOpcode();
};