#pragma once

#include "../OneRegInstr.h"

using namespace std;

class BrgtsInstr: public OneRegInstr
{
public:
	BrgtsInstr(token_pos pos);
	uint32_t GetOpcode();
};