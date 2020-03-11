#pragma once

#include "../OneRegInstr.h"

using namespace std;

class BrInstr: public OneRegInstr
{
public:
	BrInstr(token_pos pos);
	uint32_t GetOpcode();
};