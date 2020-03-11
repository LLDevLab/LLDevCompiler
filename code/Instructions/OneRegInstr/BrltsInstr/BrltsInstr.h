#pragma once

#include "../OneRegInstr.h"

using namespace std;

class BrltsInstr: public OneRegInstr
{
public:
	BrltsInstr(token_pos pos);
	uint32_t GetOpcode();
};