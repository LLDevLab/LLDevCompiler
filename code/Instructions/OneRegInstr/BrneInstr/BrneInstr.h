#pragma once

#include "../OneRegInstr.h"

using namespace std;

class BrneInstr: public OneRegInstr
{
public:
	BrneInstr(token_pos pos);
	uint32_t GetOpcode();
};