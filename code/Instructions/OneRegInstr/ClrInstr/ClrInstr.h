#pragma once

#include "../OneRegInstr.h"

using namespace std;

class ClrInstr: public OneRegInstr
{
public:
	ClrInstr(token_pos pos);
	uint32_t GetOpcode();
};