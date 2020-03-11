#pragma once

#include "../OneRegInstr.h"

using namespace std;

class PopInstr: public OneRegInstr
{
public:
	PopInstr(token_pos pos);
	uint32_t GetOpcode();
};